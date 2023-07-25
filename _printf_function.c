
#include "main.h"


void print_buffer(char buffer[], int *buff_ind);


/**

 * _printf - Printf function

 * @format: format.

 * Return:the  number of characters printed.

 */

int _printf(const char *format, ...)

{

        int i, printed = 0, num_characters = 0;

        int flags, width, precision, size, buff_len = 0;

        va_list list;

        char buffer[BUFF_SIZE];


        if (format == NULL)

                return (-1);


        va_start(list, format);


        for (i = 0; format && format[i] != '\0'; i++)

        {

                if (format[i] != '%')

                {

                        buffer[buff_ind++] = format[i];

                        if (buff_ind == BUFF_SIZE)

                                print_buffer(buffer, &buff_len);

                        /* write(1, &format[i], 1);*/

                        num_characters++;

                }

                else

                {

                        print_buffer(buffer, &buff_len);

                        flags = get_flags(format, &i);

                        width = get_width(format, &i, list);

                        precision = get_precision(format, &i, list);

                        size = get_size(format, &i);

                        ++i;

                        printed = handle_print(format, &i, list, buffer,

                                flags, width, precision, size);

                        if (printed == -1)

                                return (-1);

                        num_characters += printed;

                }

        }


        print_buffer(buffer, &buff_len);


        va_end(list);


        return (num_characters);

}


/**

 * print_buffer - Prints the contents of the buffer if it exist

 * @buffer: Array of chars

 * @buff_len: Index at which to add next char, represents the length.

 */

void print_buffer(char buffer[], int *buff_len)

{

        if (*buff_len > 0)

                write(1, &buffer[0], *buff_len);


        *buff_len = 0;

}
