#include <regex.h>


static int match_here(const char *regexp, const char *text);
static int match_star(int c, const char *regexp, const char *text);

int regex_match(const char *regexp, const char *text) {
    
    if (regexp[0] == '^') {
        return match_here(regexp + 1, text);
    }
    
    do {
        if (match_here(regexp, text)) return 1;
    } while (*text++ != '\0');
    
    return 0;
}

static int match_here(const char *regexp, const char *text) {
    
    if (regexp[0] == '\0') return 1;
    
    
    if (regexp[1] == '*') {
        return match_star(regexp[0], regexp + 2, text);
    }
    
    
    if (regexp[0] == '$' && regexp[1] == '\0') {
        return *text == '\0';
    }
    
    
    if (*text != '\0' && (regexp[0] == '.' || regexp[0] == *text)) {
        return match_here(regexp + 1, text + 1);
    }
    
    return 0;
}

static int match_star(int c, const char *regexp, const char *text) {
    do {
        
        if (match_here(regexp, text)) return 1;
    } while (*text != '\0' && (*text++ == c || c == '.'));
    
    return 0;
}
