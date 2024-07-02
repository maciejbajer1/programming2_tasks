#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    int** arr = NULL;
    int* len = NULL;
    int numOfRows = 0;

    char *input = NULL;

    len = (int*) malloc (numOfRows *sizeof (int));


    arr = (int**) malloc(numOfRows * sizeof (int*));
    input = (char*) malloc(4 * sizeof (char));


    do {
        int w = 0;
        int value = 0;
        int h = 0;
        int r = 0;
        int s = 0;
        int c = 0;
        int d = 0;
        scanf("%s", input);

        if (!(strcmp(input, "AFR"))) {
            int i;
            scanf("%i", &w);

            if (w > 0) {
                numOfRows = numOfRows + 1;

                len = (int *) realloc(len, (numOfRows * sizeof(int)));
                for (i = numOfRows - 1; i > 0; i--) {
                    *(len + i) = *(len + (i - 1));
                }
                *(len) = w;

                arr = (int **) realloc(arr, (numOfRows * sizeof(int *)));

                for (i = numOfRows - 1; i > 0; i--) {
                    *(arr + i) = *(arr + (i - 1));
                }


                i = 0;
                *(arr + i) = (int *) malloc(*(len + i) * sizeof(int));
                for (i = 0; i < w; i++) {
                    scanf("%i", &value);
                    *(*(arr) + i) = value;
                }
            }
        }
        else if (!(strcmp(input, "ALR"))) {
            int i;
            scanf("%i", &w);
            if (w > 0) {
                numOfRows = numOfRows + 1;

                int *temp_len = (int *) realloc(len, numOfRows * sizeof(int));
                len = temp_len;
                *(len + (numOfRows - 1)) = w;


                int **temp_arr = (int **) realloc(arr, numOfRows * sizeof(int *));
                arr = temp_arr;

                *(arr + (numOfRows - 1)) = (int *) malloc(w * sizeof(int));
                for (i = 0; i < w; i++) {
                    scanf("%i", &value);
                    *(*(arr + numOfRows - 1) + i) = value;
                }
            }
        } else if (!(strcmp(input, "AFC")))
        {
            scanf("%i", &h);
            int i;
            int j;

            for (i = 0; i < h; i++) {
                if (i < numOfRows) {
                    scanf("%i", &value);
                    *(len + i) = *(len + i) + 1;
                    *(arr + i) = (int *) realloc(*(arr + i), *(len + i) * sizeof(int));

                    for (j = *(len + i) - 1; j > 0; j--) {
                        *(*(arr + i) + j) = *(*(arr + i) + (j - 1));
                    }
                    *(*(arr + i)) = value;
                } else {
                    scanf("%i", &value);
                    numOfRows++;
                    int index = numOfRows - 1;
                    len = (int *) realloc(len, numOfRows * sizeof(int));
                    *(len + (index)) = 1;
                    arr = (int **) realloc(arr, numOfRows * sizeof(int *));
                    *(arr + (index)) = (int *) malloc(sizeof(int));
                    *(*(arr + index)) = value;
                }
            }
        }
        else if (!(strcmp(input, "ALC"))) {
            scanf("%i", &h);
            int i;
            int j;

            for (i = 0; i < h; i++) {
                if (i < numOfRows) {
                    scanf("%i", &value);
                    *(len + i) = *(len + i) + 1;
                    *(arr + i) = (int *) realloc(*(arr + i), *(len + i) * sizeof(int));
                    j = *(len + i) - 1;
                    *(*(arr + i) + j) = value;
                } else {
                    scanf("%i", &value);
                    numOfRows++;
                    int index = numOfRows - 1;
                    len = (int *) realloc(len, numOfRows * sizeof(int));
                    *(len + (index)) = 1;
                    arr = (int **) realloc(arr, numOfRows * sizeof(int *));
                    *(arr + (index)) = (int *) malloc(sizeof(int));
                    *(*(arr + index)) = value;
                }
            }
        }
        else if (!(strcmp(input, "IBR"))) {
            int i;
            scanf("%i", &r);

            if ((r >= 0) && (r < numOfRows)) {
                scanf("%i", &w);

                if (w > 0) {
                    numOfRows = numOfRows + 1;
                    int *newLen = realloc(len, numOfRows * sizeof(int));

                    len = newLen;


                    for (i = numOfRows - 1; i > r; i--) {
                        *(len + i) = *(len + (i - 1));
                    }
                    *(len + r) = w;

                    int **newArr = realloc(arr, numOfRows * sizeof(int *));

                    arr = newArr;

                    for (i = numOfRows - 1; i > r; i--) {
                        *(arr + i) = *(arr + (i - 1));
                    }

                    *(arr + r) = malloc(w * sizeof(int));


                    for (i = 0; i < w; i++) {
                        scanf("%i", &value);
                        *(*(arr + r) + i) = value;
                    }
                }
            }
        } else if (!(strcmp(input, "IAR"))) {
            int i;
            scanf("%i", &r);
            if ((r >= 0) && (r < numOfRows)) {

                scanf("%i", &w);

                if (w > 0) {
                    numOfRows++;
                    len = (int *) realloc(len, numOfRows * sizeof(int));
                    arr = (int **) realloc(arr, numOfRows * sizeof(int *));

                    for (i = numOfRows - 1; i > r + 1; i--) {
                        *(len + i) = *(len + i - 1);
                        *(arr + i) = *(arr + i - 1);
                    }

                    *(len + r + 1) = w;

                    *(arr + r + 1) = malloc(w * sizeof(int));

                    for (i = 0; i < w; i++) {
                        scanf("%i", &value);
                        *(*(arr + r + 1) + i) = value;
                    }
                }

            }
        } else if (!(strcmp(input, "SWR"))) {
            scanf("%i", &r);
            scanf("%i", &s);
            if ((r >= 0) && (r < numOfRows) && (s >= 0) && (s < numOfRows)) {

                int *tempPtr = *(arr + s);
                *(arr + s) = *(arr + r);
                *(arr + r) = tempPtr;

                int tempLen = *(len + s);
                *(len + s) = *(len + r);
                *(len + r) = tempLen;
            }

        } else if (!(strcmp(input, "SWC"))) {
            scanf("%i", &c);
            scanf("%i", &d);
            int i;
            if ((c >= 0) && (d >= 0)) {
                for (i = 0; i < numOfRows; i++) {
                    if ((c < *(len + i)) && (d < *(len + i))) {
                        int temp = *(*(arr + i) + c);
                        *(*(arr + i) + c) = *(*(arr + i) + d);
                        *(*(arr + i) + d) = temp;
                    }
                }
            }
        } else if (!(strcmp(input, "IBC"))) {
            scanf("%i", &c);
            scanf("%i", &h);
            int i;
            int j;
            if ((h > 0) && (c >= 0)) {
                for (i = 0; i < h; i++) {
                    if (i < numOfRows) {
                        if (c < *(len + i)) {
                            scanf("%i", &value);

                            *(len + i) = *(len + i) + 1;
                            *(arr + i) = (int *) realloc(*(arr + i), *(len + i) * sizeof(int));

                            for (j = *(len + i) - 1; j > c; j--) {
                                *(*(arr + i) + j) = *(*(arr + i) + (j - 1));
                            }
                            *(*(arr + i) + c) = value;

                        } else {
                            scanf("%i", &value);
                            *(len + i) = *(len + i) + 1;
                            int *temp_ptr = realloc(*(arr + i), (*(len + i) + 1) * sizeof(int));
                            *(arr + i) = temp_ptr;
                            j = *(len + i) - 1;
                            *(*(arr + i) + j) = value;
                        }
                    } else {
                        scanf("%i", &value);
                        numOfRows++;
                        int index = numOfRows - 1;
                        len = (int *) realloc(len, numOfRows * sizeof(int));
                        *(len + (index)) = 1;
                        arr = (int **) realloc(arr, numOfRows * sizeof(int *));
                        *(arr + (index)) = (int *) malloc(sizeof(int));
                        *(*(arr + index)) = value;
                    }
                }
            }
        } else if (!(strcmp(input, "IAC"))) {
            scanf("%i", &c);
            scanf("%i", &h);
            int i;
            int j;
            if ((h > 0) && (c >= 0)) {
                for (i = 0; i < h; i++) {
                    if (i < numOfRows) {
                        if (c < *(len + i)) {
                            scanf("%i", &value);
                            *(len + i) = *(len + i) + 1;
                            *(arr + i) = (int *) realloc(*(arr + i), *(len + i) * sizeof(int));

                            for (j = *(len + i) - 1; j > (c + 1); j--) {
                                *(*(arr + i) + j) = *(*(arr + i) + (j - 1));
                            }
                            *(*(arr + i) + (c + 1)) = value;

                        } else {
                            scanf("%i", &value);
                            *(len + i) = *(len + i) + 1;
                            *(arr + i) = (int *) realloc(*(arr + i), *(len + i) * sizeof(int));
                            j = *(len + i) - 1;
                            *(*(arr + i) + j) = value;
                        }
                    } else {
                        scanf("%i", &value);
                        numOfRows++;
                        int index = numOfRows - 1;
                        len = (int *) realloc(len, numOfRows * sizeof(int));
                        *(len + (index)) = 1;
                        arr = (int **) realloc(arr, numOfRows * sizeof(int *));
                        *(arr + (index)) = (int *) malloc(sizeof(int));
                        *(*(arr + index)) = value;
                    }
                }
            }
        } else if (!(strcmp(input, "ISB"))) {
            scanf("%i", &r);
            scanf("%i", &c);
            scanf("%i", &h);
            scanf("%i", &w);
            int i;
            int j;
            int k;
            int z;
            int currRow;
            int c2;
            c2 = c;

            if ((h > 0) && (w > 0)) {
                for (i = 0; i < h; i++) {
                    currRow = r + i;
                    if (currRow < numOfRows) {
                        if (c < *(len + currRow)) {
                            c2 = c;
                            *(len + currRow) = *(len + currRow) + w;
                            *(arr + currRow) = (int *) realloc(*(arr + currRow), *(len + currRow) * sizeof(int));

                            for (j = *(len + currRow) - 1; j >= (c2 + w); j--) {
                                *(*(arr + currRow) + j) = *(*(arr + currRow) + (j - w));
                            }
                            for (k = 0; k < w; k++) {
                                scanf("%i", &value);
                                *(*(arr + currRow) + c2) = value;
                                c2++;
                            }
                        } else {
                            for (j = 0; j < w; j++) {

                                scanf("%i", &value);

                                *(len + currRow) = *(len + currRow) + 1;
                                *(arr + currRow) = (int *) realloc(*(arr + currRow), *(len + currRow) * sizeof(int));
                                *(*(arr + currRow) + (*(len + currRow) - 1)) = value;
                            }
                        }
                    } else {
                        numOfRows++;
                        int index = numOfRows - 1;
                        len = (int *) realloc(len, numOfRows * sizeof(int));
                        *(len + (index)) = w;
                        arr = (int **) realloc(arr, numOfRows * sizeof(int *));
                        *(arr + (index)) = (int *) malloc(w * sizeof(int));

                        for (z = 0; z < w; z++) {
                            scanf("%i", &value);
                            *(*(arr + index) + z) = value;
                        }
                    }
                }
            }
        } else if (!(strcmp(input, "DFR"))) {
            if (numOfRows != 0) {
                int i;
                free((*arr));
                (*arr) = NULL;

                for (i = 0; i < numOfRows - 1; i++) {
                    *(arr + i) = *(arr + i + 1);
                    *(len + i) = *(len + i + 1);
                }
                numOfRows--;
                arr = (int **) realloc(arr, numOfRows * sizeof(int *));
                len = (int *) realloc(len, numOfRows * sizeof(int));

            }
        } else if (!(strcmp(input, "DLR"))) {
            if (numOfRows != 0) {
                int i;
                free(*(arr + (numOfRows - 1)));
                *(arr + (numOfRows - 1)) = NULL;
                numOfRows--;
                arr = (int **) realloc(arr, numOfRows * sizeof(int *));
                len = (int *) realloc(len, numOfRows * sizeof(int));
            }
        } else if (!(strcmp(input, "RMR"))) {
            scanf("%i", &r);

            if ((r >= 0) && (r < numOfRows)) {
                int i;
                free(*(arr + r));
                *(arr + r) = NULL;

                for (i = r; i < numOfRows - 1; i++) {
                    *(arr + i) = *(arr + i + 1);
                    *(len + i) = *(len + i + 1);
                }
                numOfRows--;
                arr = (int **) realloc(arr, numOfRows * sizeof(int *));
                len = (int *) realloc(len, numOfRows * sizeof(int));

            }

        } else if (!(strcmp(input, "DFC"))) {
            if (numOfRows != 0) {
                int i;
                int j;
                for (i = 0; i < numOfRows; i++) {
                    if (*(len + i) > 1) {
                        for (j = 0; j < (*(len + i)) - 1; j++) {
                            *(*(arr + i) + j) = *(*(arr + i) + (j + 1));
                        }

                        *(len + i) = *(len + i) - 1;
                        *(arr + i) = (int *) realloc(*(arr + i), *(len + i) * sizeof(int));
                    } else {
                        free(*(arr + i));
                        *(arr + i) = NULL;
                        for (j = i; j < numOfRows - 1; j++) {
                            *(arr + j) = *(arr + j + 1);
                            *(len + j) = *(len + j + 1);
                        }
                        numOfRows--;
                        arr = (int **) realloc(arr, numOfRows * sizeof(int *));
                        len = (int *) realloc(len, numOfRows * sizeof(int));
                        i--;
                    }
                }
            }
        } else if (!(strcmp(input, "DLC"))) {
            if (numOfRows != 0) {
                int i;
                int j;
                for (i = 0; i < numOfRows; i++) {
                    if (*(len + i) > 1) {
                        *(len + i) = *(len + i) - 1;
                        *(arr + i) = (int *) realloc(*(arr + i), *(len + i) * sizeof(int));

                    } else {
                        free(*(arr + i));
                        *(arr + i) = NULL;
                        for (j = i; j < numOfRows - 1; j++) {
                            *(arr + j) = *(arr + j + 1);
                            *(len + j) = *(len + j + 1);
                        }
                        numOfRows--;
                        arr = (int **) realloc(arr, numOfRows * sizeof(int *));
                        len = (int *) realloc(len, numOfRows * sizeof(int));
                        i--;
                    }
                }
            }
        } else if (!(strcmp(input, "RMC"))) {
            scanf("%i", &c);
            int i;
            int j;
            for (i = 0; i < numOfRows; i++) {
                if (c < *(len + i)) {
                    if (*(len + i) > 1) {
                        for (j = c; j < (*(len + i)) - 1; j++) {
                            *(*(arr + i) + j) = *(*(arr + i) + (j + 1));
                        }

                        *(len + i) = *(len + i) - 1;
                        *(arr + i) = (int *) realloc(*(arr + i), *(len + i) * sizeof(int));
                    } else {
                        free(*(arr + i));
                        *(arr + i) = NULL;
                        for (j = i; j < numOfRows - 1; j++) {
                            *(arr + j) = *(arr + j + 1);
                            *(len + j) = *(len + j + 1);
                        }
                        numOfRows--;
                        arr = (int **) realloc(arr, numOfRows * sizeof(int *));
                        len = (int *) realloc(len, numOfRows * sizeof(int));
                        i--;
                    }
                }
            }
        } else if (!(strcmp(input, "RMB")))
        {
            scanf("%i", &r);
            scanf("%i", &h);
            scanf("%i", &c);
            scanf("%i", &w);
            int i = 0;
            int j = 0;
            int k = 0;
            int index;
            int l2 = 0;
            int l1 = 0;
            int l = 0;
            int p = 0;
            int index2 = r + h;
            if (r + h > numOfRows)
            {
                index2 = numOfRows;
            }
            if ((r >= 0) && (r < numOfRows) && (c >= 0) && (w > 0) && (h > 0))
            {
                for (i = r; i < index2; i++)
                {

                    if (c < *(len + i))
                    {
                        int k;
                        for (k = c; k + w < *(len + i); k++)
                        {
                            *(*(arr + i) + k) = *(*(arr + i) + k + w);
                        }

                        int cn = w;
                        if (c + w > *(len + i))
                        {
                            cn = *(len + i) - c;
                        }
                        if (cn > 0)
                        {
                            *(arr + i) = (int*)realloc(*(arr + i), sizeof(int) * (*(len + i) - cn));
                            (*(len + i)) = (*(len + i)) - cn;
                        }

                        if ((*(len + i)) <= 0)
                        {
                            free((*(arr + i)));
                            *(arr + i) = NULL;
                        }


                    }
                }
                for (i = r; i < index2; i++)
                {

                    if (*(arr + i) == NULL)
                    {
                        for (k = i; k < numOfRows - 1; k++)
                        {
                            *(arr + k) = *(arr + k + 1);
                            *(len + k) = *(len + k + 1);
                        }
                        numOfRows--;

                        *(arr + numOfRows) = NULL;
                        *(len + numOfRows) = 0;

                        arr = (int **)realloc(arr, numOfRows * sizeof(int*));
                        len = (int *)realloc(len, numOfRows * sizeof(int));
                        l1--;
                        i--;
                        index2--;
                    }
                }
            }
        }
        else if (!(strcmp(input, "WRF")))
        {

            int i = 0;
            int j = 0;
            int a = 0;
            char *file = (char*)calloc(17, sizeof(char));
            scanf("%s", file);

            FILE* f = fopen(file, "wb");
            fprintf(f, "%d\n", numOfRows);

            for (i = 0; i < numOfRows; i++)
            {
                a = *(len + i) >> 8;
                fwrite(&a, 1, 1, f);
                a = *(len + i);
                fwrite(&a, 1, 1, f);

                for (j = 0; j < *(len + i); j++)
                {
                    a = (*((*(arr + i) + j)) >> 24);
                    fwrite(&a, 1, 1, f);
                    a = (*((*(arr + i) + j)) >> 16);
                    fwrite(&a, 1, 1, f);
                    a = (*((*(arr + i) + j)) >> 8);
                    fwrite(&a, 1, 1, f);
                    a = *((*(arr + i) + j));
                    fwrite(&a, 1, 1, f);
                }
            }
            fclose(f);
            if(file!= NULL){
                free(file);
            }
            file = NULL;

        }
        else if (!(strcmp(input, "RDF")))
        {

            int i = 0;
            int j = 0;
            int temp;
            char cha;
            char* file = (char*)calloc(17, sizeof(char));
            scanf("%s", file);

            if(len != NULL){
                free(len);
                len = NULL;
            }

            for(i = (numOfRows - 1); i >= 0; i--)
            {

                if(*(arr + i) != NULL){
                    free(*(arr + i));
                    *(arr + i) = NULL;
                }
            }

            if(arr != NULL){
                free(arr);
                arr = NULL;
            }

            numOfRows = 0;

            FILE* f = fopen(file, "rb");
            fscanf(f, "%d", &temp);
            fscanf(f, "%c", &cha);

            numOfRows = temp;
            arr = (int**) calloc(temp, sizeof (int*));
            len = (int*) calloc(temp, sizeof (int));

            for (i = 0; i < numOfRows; i++)
            {
                int x = 0;
                temp = 0;

                fread(&temp, 1, 1, f);
                int z = (temp << 8);
                x += z;
                fread(&temp, 1, 1, f);
                x += temp;

                *(arr + i) = (int*) realloc(*(arr + i), x * sizeof (int));
                *(len + i) = x;

                for (j = 0; j < x; j++)
                {
                    int a = 0;
                    temp = 0;

                    fread(&temp, 1, 1, f);
                    a += (temp << 24);
                    fread(&temp, 1, 1, f);
                    a += (temp << 16);
                    fread(&temp, 1, 1, f);
                    a += (temp << 8);
                    fread(&temp, 1, 1, f);
                    a += temp;
                    *(*(arr + i) + j) = a;
                }

            }
            fclose(f);
            if(file != NULL){
                free(file);
                file = NULL;
            }
        }
        else if (!(strcmp(input, "PRT")))
        {
            if (arr == NULL)
            {
                printf("0\n");
            }
            else
            {
                printf("%i\n", numOfRows);
                int i;
                int j;
                for (i = 0; i < numOfRows; i++)
                {
                    printf("%i", *(len + i));

                    for (j = 0; j < *(len + i); j++)
                    {
                        printf(" %i", *(*(arr + i) + j));
                    }
                    printf("\n");
                }
            }
        }
    }
    while (strcmp(input, "END") != 0);


    if (len != NULL)
    {
        free(len);
        len = NULL;
    }

    int i;
    for (i = (numOfRows - 1); i >= 0; i--)
    {
        if (*(arr + i) != NULL)
        {
            free(*(arr + i));
            *(arr + i) = NULL;
        }
    }

    if (arr != NULL)
    {
        free(arr);
        arr = NULL;
    }

    if (input != NULL)
    {
        free(input);
        input = NULL;
    }
    return 0;
}