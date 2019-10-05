#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // ask for a number
    int h = 0;
    printf("How many steps high is the pyramid? ");
    h = get_int();
    
    while (h < 0 || h > 23)
    {
        printf("The height must be a whole number between zero and 24. Try again: ");
        h = get_int();
    }
    
    // on each row
    for (int i = 0; i < h; i++)   
    {
        // print leading spaces
        
        for (int s = 0; s < h - i - 1; s++)
        {
            printf(" ");
        }   
        
        // print left-side hashtags
        for (int x = h - i - 1; x <= h; x++)
        {
            printf("#");
                
        }
        // print gap
        printf("  ");
          
        // print right-side hashtags
        for (int x = h - i - 1; x <= h; x++)
        {
                printf("#");
        }
        
        // move to new line
        printf("\n");
    }
    return 0;
}
