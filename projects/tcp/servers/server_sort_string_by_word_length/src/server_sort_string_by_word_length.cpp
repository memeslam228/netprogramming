#include "server_sort_string_by_word_length.h"


int compare (const void * a, const void * b) {
    size_t fa = strlen((const char *)a);
    size_t fb = strlen((const char *)b);
    return (fa > fb) - (fa < fb);
}

int getWords(char *base, char target[40][30])
{
	int n=0,i,j=0;
	
	for(i=0;1;i++)
	{
		if(base[i]!=' '){
			target[n][j++]=base[i];
		}
		else{
			target[n][j++]='\0';
			n++;
			j=0;
		}
		if(base[i]=='\0')
		    break;
	}
	return n;
	
}

void sortString(char rq[], char rs[]) {

  char strings[40][30];
  int length = getWords(rq, strings);

  qsort(strings, length, 30, compare);

  for (int i = 0; i <= length; i++) {
    strcat(rs, strcat(strings[i], " "));
  }
  

	
}


void handle_connection(SOCKET socket, sockaddr_in* addr) {
    char* str_in_addr = inet_ntoa(addr->sin_addr);
    printf("[%s]>>%s\n", str_in_addr, "Establish new connection");
	int rc = 1;
    while (rc > 0) {
        char request[256] = "";
		memset(&request, sizeof(request), 0);

		char response[256] = "";
		memset(&response, sizeof(response), 0);

        rc = recv(socket, (char*)&request, sizeof(request), 0);
		sortString(request, response);
		rc = send(socket, (char*)&response, sizeof(response), 0);
    }
    close_socket(socket);
    printf("[%s]>>%s", str_in_addr, "Close incomming connection");
}
