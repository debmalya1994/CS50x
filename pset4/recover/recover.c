#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main (void){   

    FILE* data = fopen("card.raw", "r");
    
    if (data == NULL){
        fprintf(stderr, "Cannot create card.raw.\n");
        return 1;
    }

    FILE* output_file = NULL;
    int images = 0;
    
    while (!feof(data)){
        BYTE buffer[512];

        char imgname[8];
        
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1)){
            if (output_file != NULL){
                fclose(output_file);
            }
            sprintf(imgname, "%03d.jpg", images);
            output_file = fopen(imgname, "w");
            images++;
            fwrite(buffer, sizeof(buffer), 1, output_file);
        }
        else{
            if (images > 0){
                fwrite(buffer, sizeof(buffer), 1, output_file);            
            }
        }
        fread(buffer, sizeof(buffer), 1, data);
        
    }
    if (images > 0){
        fclose(output_file);
    }
    fclose(data);

    return 0;
}