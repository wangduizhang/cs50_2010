#include <stdio.h>
#include <stdlib.h>
//复制二进制文件

#define MAXLEN 1024


int main(int argc, char *argv[])

{

    if( argc < 3 )

    {

        printf("usage: %s %s/n", argv[0], "infile outfile");

        exit(1);

    }

   

    FILE * outfile, *infile;

    outfile = fopen(argv[2], "wb" );

    infile = fopen(argv[1], "rb");

    unsigned char buf[MAXLEN];

    if( outfile == NULL || infile == NULL )

    {

        printf("%s, %s",argv[1],"not exit/n");

        exit(1);

    }   

   

    int rc;

    while( (rc = fread(buf,sizeof(unsigned char), MAXLEN,infile)) != 0 )

    {

        fwrite( buf, sizeof( unsigned char ), rc, outfile );

} 

fclose(infile);

fclose(outfile);

 return 0;

}
 