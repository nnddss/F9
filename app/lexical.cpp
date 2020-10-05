#include<bits/stdc++.h>
using namespace std;
long long dis[500010];
char  token[50];
char c;
int main(){
	FILE *fp;
	fp = fopen("1.txt", "r");
    char  keywordname[30][20]={"","Begin","End","For","Do","If","Then","Else","Ident","Int","Colon","Plus","Star",
	"Comma","LParenthesis","RParenthesis","Assign"};
    char  keyword[30][10]={"","BEGIN","END","FOR","DO","IF","THEN","ELSE","","",":","+","*",",","(",")",":="};
   while(c=fgetc(fp)){
   	if(c==' '||c=='\n'||c=='\r')
   		continue;
   	else if(c==-1)
   		return 0;
   	else if(c==':'){
   		c=fgetc(fp);
   		if(c=='=')
   		printf("Assign\n");
   		else{
   		printf("Colon\n");	
   		fseek(fp, -1, SEEK_CUR);
		}
		continue;
	   }
   	else if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')||c=='+'||c=='*'||c==','||c=='('||c==')'){
   		memset(token,0,50);
		token[0]=c;
	   }
	else {
		printf("Unknow\n");
		return 0;
	}
	int j=11;
	for(;j<=15;j++){
		if(c==keyword[j][0]){
			printf("%s\n",keywordname[j]);
			continue;
		}
	} 
	
   	 
   	int k=0;
   	if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
   		int i=1;
   		while(1){
   			c=fgetc(fp);
   			if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')){
   				token[i++]=c;
			   }
			else {
				fseek(fp, -1, SEEK_CUR);
				break;
			}
		   }
		for(i=1;i<=15;i++){
			if(strcmp(token,keyword[i])==0){
				printf("%s\n",keywordname[i]);
				k=1;
				break;
			}
		}
   		if(k==0)
   			printf("%s(%s)\n",keywordname[8],token);
   		if(c==-1)
   			return 0;
	   }
	else if(c>='0'&&c<='9'){
		int i;
   		for(i=1;;i++){
   			c=fgetc(fp);
   			if(c>='0'&&c<='9'){
   				token[i]=c;
			   }
			else{
				fseek(fp, -1, SEEK_CUR);
				printf("%s(%d)\n",keywordname[9],atoi(token));
				break;
			}
			if(c==-1)
   				return 0;
		   }
	}

   }

    
    return 0;
}
