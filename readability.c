#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<math.h>

int wordqtf(string texto); //Conta quantidade de palavras
int letterqtf(string texto);
int sentenceqtf(string texto);

int main(void){
float L=.0;
float S=.0;

string texto=get_string("Text: ");

L=(letterqtf(texto)*100)/(float)wordqtf(texto);
S=(sentenceqtf(texto)*100)/(float)wordqtf(texto);

int index=round(0.0588*L-0.296*S-15.8);
float index2=0.0588*L-0.296*S-15.8;

if(index<1.0){
    printf("Before Grade 1");
}
else if(index>16.0){
    printf("Grade 16+\n");
}
else
    printf("Grade %i\n",index);

printf("\nGrade %f.\n",index2);

printf("Letter: %i\nSentence: %i\nWord: %i\n",letterqtf(texto),sentenceqtf(texto),wordqtf(texto));
}
int wordqtf(string texto){ //Conta quantidade de palavras
    int j=0;
   /* if(texto[0]==040){
        j=0;
    }
    else
        j=1;*/

    for(int i=0;texto[i]!=000;i++){
        if(texto[i]==041||texto[i]==042||texto[i]==054||texto[i]==056||texto[i]==072||texto[i]==073||texto[i]==077){ //Se i for um caracter especial
            if(texto[i+1]!=040&&texto[i+1]!=047&&texto[i+1]!=042){
                j+=1; //Conte uma palavra
                //printf("%c%i",texto[i+1],j);
            }
            else if(texto[i]==055){
                continue;
            }
            }
        else if(texto[i]==040&&texto[i+1]!=040){
            if(texto[i+1]==047||texto[i+1]==042){
                continue;
        }
            else
            j+=1;
            //printf("%c%i",texto[i+1],j);
        }
    }
    return j;
}


int letterqtf(string texto){
    int j=0;
    for(int i=0,len=strlen(texto);i<len;++i){
        switch(texto[i]){
            case 040:
            case 041:
            case 042:
            case 047:
            case 054:
            case 055:
            case 056:
            case 072:
            case 073:
            case 077:
                continue;
            default:
                j+=1;
        }
    }
    return j;
}

int sentenceqtf(string texto){
int count=0;
for(int i=0;texto[i]!=000;++i){
    if(texto[i]==041||texto[i]==056||texto[i]==072||texto[i]==077){
        count++;
    }
    else
        continue;
}

return count;
}
// L é a media do numero de letras a cada 100 palavras
//Logo, (L=L1+L2...L100/200)+(L101+L102...L200/200)
//Porém, Ln=strlen(texto) - caracteres especiais e espaços
//count=Ln
//count/100=quantidade de letras a cada 100 palavras;
//while(count/100<count)
//int sum=0;
//{
//sum+=1
//}
