#ifndef UTILS_H
#define UTILS_H

void println(const char* fmt, ...);

char* getln();

int toInt(const char* string);
int getInt();

float toFloat(const char* string, ...); 
// second argument is a boolean if to accept comma as dot

float getFloat();
float getFloatComma();

#endif
