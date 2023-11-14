#include <stdio.h>
#include <stdarg.h>

int _printf(const char* format, ...)
{
    va_list args;
    va_start(args, format);
 int _printf(const char* format, ...)
{
    int count = 0; 

    va_list args;
    va_start(args, format);
    
    while (*format != '\0')
    {
	    if (*format == '%')
	    {
		    format++;
            
            /* Handle conversion specifiers*/
		    switch (*format)
		    {
		    case 'c':
                {
                    int ch = va_arg(args, int);
                    putchar(ch);
                    count++;
                    break;
                }
                case 's':
                {
                    char* str = va_arg(args, char*);
                    count += printf("%s", str);
                    break;
                }
                case '%':
                {
                    putchar('%');
                    count++;
                    break;
                }
                case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    count += printf("%d", num);
                    break;
                }
                default:
                    break;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }
        
        format++;
    }
    
    va_end(args);
    
    return count;
}

int main()
{
    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "Hello, World!");
    _printf("Percentage: %%\n");
    _printf("Integer: %d\n", 42);
    
    return 0;
}
