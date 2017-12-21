#include <stdio.h>
#include <string.h>

char *strcpy_array( char dest[], char src[] )
{
    int i = 0;
    while(src[i] != '\0')
    {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
    return dest;
}

char *strcpy_pointer( char *dest, char *src )
{
    while(*src != '\0')
    {
        *dest = *src;
        ++src;
        ++dest;
    }
    *dest = '\0';
    return dest;
}

int main()
{
    char src_str[50], dest_str1[50], dest_str2[50];

    printf("Input string to be copied: ");
    gets(src_str);

    printf("\nString copied with arrays: %s", strcpy_array(dest_str1, src_str));

    strcpy_pointer(dest_str2, src_str);
    printf("\nString copied with pointers: %s", dest_str2);
}
