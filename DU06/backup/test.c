#ifndef __PROGTEST__
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#endif /* __PROGTEST__ */


int findLengh(char *point){
  int count = 0;
  for(char * finder = point; *finder != '\0'; finder ++){
    count++;
  }
  return count;
}



char             * wordWrap                                ( int               width,
                                                             const char      * src )
{
char * outch = (char *)malloc(findLengh((char*)src)*sizeof(char));
char * tmpch = (char *)malloc(20*sizeof(char));
char *poich = (char*)src;



int count = 0, flag = 0, newLine = 1, firstWord = 1, when = 0;
int widthLine = width, test = 0;



while (strlen(poich)){
    if ((sscanf(poich, "%s%n", tmpch, &count))!=1)
      return NULL;
    (strlen(tmpch)>widthLine)?(newLine=1):(newLine=0);


    //printf(">%s<\nwidthLine %d\n",outch, widthLine);
    //printf("%s\n count -> %d\n", tmpch, count);
    //scanf("%d",&test);


    if (count>(strlen(tmpch)+1)){

      for (int i = 0; i < (count-strlen(tmpch)); i++ ){
        if (src[when+i]=='\n')
          flag++;
        if (flag == 2){


          if ((strlen(tmpch)<=width)){
            strcat(outch, "\n\n");
            strcat(outch, tmpch);
            newLine = 0;
            firstWord = 0;
            widthLine=width;
            widthLine-=strlen(tmpch);
            break;
          }
          else{
            return NULL;
          }
        }
      }
      if (flag!=2){

        if (newLine == 1){

          if (strlen(tmpch)<=width){
            strcat(outch, "\n");
            strcat(outch, tmpch);
            widthLine=width;
            widthLine-=strlen(tmpch);
            firstWord = 0;
            newLine = 0;
          }
          else{
            return NULL;
          }

        }
        else{
          if (firstWord!=1) {
            if ((strlen(tmpch)+1)<=widthLine){
              strcat(outch, " ");
              strcat(outch, tmpch);
              widthLine -= strlen(tmpch)+1;
            }
            else{
              if(strlen(tmpch)<=width){
                strcat(outch, "/n");
                strcat(outch, tmpch);
                widthLine = width - strlen(tmpch);
              }
              else{return NULL;}
            }
          }
          else{
            firstWord = 0;
            strcat(outch, tmpch);
            widthLine=width;
            widthLine -= strlen(tmpch);
          }


          }
        }
      }
    else{
      if (newLine == 1){

        if (strlen(tmpch)<=width){
          strcat(outch, "\n");
          strcat(outch, tmpch);
          widthLine=width;
          widthLine-=strlen(tmpch);
          newLine = 0;
          firstWord = 0;
        }
        else{
          return NULL;
        }


      }
      else{
        if (firstWord!=1) {
          if((strlen(tmpch)+1)<=widthLine){
            strcat(outch, " ");
            strcat(outch, tmpch);
            widthLine -= strlen(tmpch)+1;
          }
          else{
            strcat(outch, "\n");
            strcat(outch, tmpch);
            widthLine = width - strlen(tmpch);
          }


        }
        else{
          firstWord = 0;
          strcat(outch, tmpch);
          widthLine=width;
          widthLine -= strlen(tmpch);
        }
      }
}
when += count;
flag = 0;
poich += count;

}
strcat(outch, "\n");
printf("%s\n", outch);
free(tmpch);
return outch;
}

#ifndef __PROGTEST__
int                main                                     ( void )
{
  char * res;
  char test;
  const char * s0 =
    "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Integer metus\n"
    "pede, pretium vitae, rhoncus et, auctor sit amet, ligula. Integer volutpat\n"
    "orci et elit. Nunc tempus, urna at sollicitudin rutrum, arcu libero rhoncus\n"
    "lectus, vitae feugiat purus orci ultricies turpis. Pellentesque habitant\n"
    "morbi tristique senectus et netus et malesuada fames ac turpis egestas. Nam\n"
    "in pede. Etiam eu sem id urna ultricies congue. Vestibulum porttitor\n"
    "ultrices neque. Mauris semper, mauris ut feugiat ultricies, augue purus\n"
    "tincidunt  elit, eu interdum ante nisl ac ante. Pellentesque dui. Vestibulum\n"
    "pretium, augue non cursus pretium, nibh dolor laoreet leo, sed pharetra pede\n"
    "libero non diam.";
  const char * s1 =
    "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Integer metus\n"
    "pede, pretium vitae, rhoncus et, auctor sit amet, ligula. Integer volutpat\n"
    "orci et elit. Nunc tempus, urna at sollicitudin rutrum, arcu libero rhoncus\n"
    "lectus, vitae feugiat purus orci ultricies turpis. Pellentesque habitant\n"
    "morbi tristique senectus et netus et malesuada fames ac turpis egestas. Nam\n"
    "in pede. Etiam eu sem id urna ultricies congue. Vestibulum porttitor\n"
    "ultrices neque. Mauris semper, mauris ut feugiat ultricies, augue purus\n"
    "tincidunt  elit, eu interdum ante nisl ac ante. Pellentesque dui. Vestibulum\n"
    "pretium, augue non cursus pretium, nibh\tdolor laoreet leo, sed pharetra pede\n"
    "libero non diam.\n"
    "\n"
    "Proin est nisi,                     gravida ac, vulputate id, fringilla sit\n"
    "amet, magna. Nam congue cursus magna. In malesuada, velit a gravida sodales,\n"
    "dolor nisl vestibulum orci, sit amet sagittis mauris tellus nec purus. Nulla\n"
    "eget risus. Quisque nec sapien blandit odio convallis ullamcorper. Lorem\n"
    "ipsum dolor sit amet, consectetuer adipiscing elit. Pellentesque cursus.\n"
    "Aliquam tempus neque vitae libero molestie ut auctor.\n"
    "\n"
    "\n"
    "\n"
    "In nec massa eu tortor vulputate suscipit.\tNam tristique magna nec pede. Sed\n"
    "a nisi. Nulla sed augue ut risus placerat porttitor. Ut aliquam. Nulla\n"
    "facilisi. Nulla vehicula nibh ac sapien. Nunc facilisis dapibus ipsum. Donec\n"
    "sed mauris. Nulla quam nisi, laoreet non, dignissim posuere, lacinia nec,\n"
    "turpis. Mauris malesuada nisi sed enim. In hac habitasse platea dictumst.\n"
    "Fusce    faucibus, turpis nec auctor posuere, nulla tellus scelerisque metus,\n"
    "quis molestie mi dui id quam. Mauris vestibulum. Nam ullamcorper.\n"
    "\n";
  res = wordWrap ( 40, s0 );
  assert ( ! strcmp ( res,
    "Lorem ipsum dolor sit amet, consectetuer\n"
    "adipiscing elit. Integer metus pede,\n"
    "pretium vitae, rhoncus et, auctor sit\n"
    "amet, ligula. Integer volutpat orci et\n"
    "elit. Nunc tempus, urna at sollicitudin\n"
    "rutrum, arcu libero rhoncus lectus,\n"
    "vitae feugiat purus orci ultricies\n"
    "turpis. Pellentesque habitant morbi\n"
    "tristique senectus et netus et malesuada\n"
    "fames ac turpis egestas. Nam in pede.\n"
    "Etiam eu sem id urna ultricies congue.\n"
    "Vestibulum porttitor ultrices neque.\n"
    "Mauris semper, mauris ut feugiat\n"
    "ultricies, augue purus tincidunt elit,\n"
    "eu interdum ante nisl ac ante.\n"
    "Pellentesque dui. Vestibulum pretium,\n"
    "augue non cursus pretium, nibh dolor\n"
    "laoreet leo, sed pharetra pede libero\n"
    "non diam.\n" ) );
  free ( res );



  res = wordWrap ( 120, s0 );
  assert ( ! strcmp ( res,
    "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Integer metus pede, pretium vitae, rhoncus et, auctor sit\n"
    "amet, ligula. Integer volutpat orci et elit. Nunc tempus, urna at sollicitudin rutrum, arcu libero rhoncus lectus, vitae\n"
    "feugiat purus orci ultricies turpis. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac\n"
    "turpis egestas. Nam in pede. Etiam eu sem id urna ultricies congue. Vestibulum porttitor ultrices neque. Mauris semper,\n"
    "mauris ut feugiat ultricies, augue purus tincidunt elit, eu interdum ante nisl ac ante. Pellentesque dui. Vestibulum\n"
    "pretium, augue non cursus pretium, nibh dolor laoreet leo, sed pharetra pede libero non diam.\n" ) );
  free ( res );

  res = wordWrap ( 10, s1 );
  assert ( res == NULL );

  res = wordWrap ( 40, s1 );
  assert ( ! strcmp ( res,
    "Lorem ipsum dolor sit amet, consectetuer\n"
    "adipiscing elit. Integer metus pede,\n"
    "pretium vitae, rhoncus et, auctor sit\n"
    "amet, ligula. Integer volutpat orci et\n"
    "elit. Nunc tempus, urna at sollicitudin\n"
    "rutrum, arcu libero rhoncus lectus,\n"
    "vitae feugiat purus orci ultricies\n"
    "turpis. Pellentesque habitant morbi\n"
    "tristique senectus et netus et malesuada\n"
    "fames ac turpis egestas. Nam in pede.\n"
    "Etiam eu sem id urna ultricies congue.\n"
    "Vestibulum porttitor ultrices neque.\n"
    "Mauris semper, mauris ut feugiat\n"
    "ultricies, augue purus tincidunt elit,\n"
    "eu interdum ante nisl ac ante.\n"
    "Pellentesque dui. Vestibulum pretium,\n"
    "augue non cursus pretium, nibh dolor\n"
    "laoreet leo, sed pharetra pede libero\n"
    "non diam.\n"
    "\n"
    "Proin est nisi, gravida ac, vulputate\n"
    "id, fringilla sit amet, magna. Nam\n"
    "congue cursus magna. In malesuada, velit\n"
    "a gravida sodales, dolor nisl vestibulum\n"
    "orci, sit amet sagittis mauris tellus\n"
    "nec purus. Nulla eget risus. Quisque nec\n"
    "sapien blandit odio convallis\n"
    "ullamcorper. Lorem ipsum dolor sit amet,\n"
    "consectetuer adipiscing elit.\n"
    "Pellentesque cursus. Aliquam tempus\n"
    "neque vitae libero molestie ut auctor.\n"
    "\n"
    "In nec massa eu tortor vulputate\n"
    "suscipit. Nam tristique magna nec pede.\n"
    "Sed a nisi. Nulla sed augue ut risus\n"
    "placerat porttitor. Ut aliquam. Nulla\n"
    "facilisi. Nulla vehicula nibh ac sapien.\n"
    "Nunc facilisis dapibus ipsum. Donec sed\n"
    "mauris. Nulla quam nisi, laoreet non,\n"
    "dignissim posuere, lacinia nec, turpis.\n"
    "Mauris malesuada nisi sed enim. In hac\n"
    "habitasse platea dictumst. Fusce\n"
    "faucibus, turpis nec auctor posuere,\n"
    "nulla tellus scelerisque metus, quis\n"
    "molestie mi dui id quam. Mauris\n"
    "vestibulum. Nam ullamcorper.\n" ) );
  free ( res );

  res = wordWrap ( 80, s1 );
  assert ( ! strcmp ( res,
    "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Integer metus pede,\n"
    "pretium vitae, rhoncus et, auctor sit amet, ligula. Integer volutpat orci et\n"
    "elit. Nunc tempus, urna at sollicitudin rutrum, arcu libero rhoncus lectus,\n"
    "vitae feugiat purus orci ultricies turpis. Pellentesque habitant morbi tristique\n"
    "senectus et netus et malesuada fames ac turpis egestas. Nam in pede. Etiam eu\n"
    "sem id urna ultricies congue. Vestibulum porttitor ultrices neque. Mauris\n"
    "semper, mauris ut feugiat ultricies, augue purus tincidunt elit, eu interdum\n"
    "ante nisl ac ante. Pellentesque dui. Vestibulum pretium, augue non cursus\n"
    "pretium, nibh dolor laoreet leo, sed pharetra pede libero non diam.\n"
    "\n"
    "Proin est nisi, gravida ac, vulputate id, fringilla sit amet, magna. Nam congue\n"
    "cursus magna. In malesuada, velit a gravida sodales, dolor nisl vestibulum orci,\n"
    "sit amet sagittis mauris tellus nec purus. Nulla eget risus. Quisque nec sapien\n"
    "blandit odio convallis ullamcorper. Lorem ipsum dolor sit amet, consectetuer\n"
    "adipiscing elit. Pellentesque cursus. Aliquam tempus neque vitae libero molestie\n"
    "ut auctor.\n"
    "\n"
    "In nec massa eu tortor vulputate suscipit. Nam tristique magna nec pede. Sed a\n"
    "nisi. Nulla sed augue ut risus placerat porttitor. Ut aliquam. Nulla facilisi.\n"
    "Nulla vehicula nibh ac sapien. Nunc facilisis dapibus ipsum. Donec sed mauris.\n"
    "Nulla quam nisi, laoreet non, dignissim posuere, lacinia nec, turpis. Mauris\n"
    "malesuada nisi sed enim. In hac habitasse platea dictumst. Fusce faucibus,\n"
    "turpis nec auctor posuere, nulla tellus scelerisque metus, quis molestie mi dui\n"
    "id quam. Mauris vestibulum. Nam ullamcorper.\n" ) );
  free ( res );

  return 0;
}
#endif /* __PROGTEST__ */
