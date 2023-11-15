#ifndef UTILS_H
#define UTILS_H

void println(const char *fmt, ...);
void printwln(const char *fmt, ...);
char *getln();

int showInteractiveMenu(const char *title, const char *options[], int optionsSize);

#endif // UTILS_H
