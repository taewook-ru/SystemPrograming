#include <stdio.h>



int main()

{

    WSADATA wsaData;

    SOCKET    sockSvr;

    SOCKET    sockSS;

    int        nlen;

    struct    sockaddr_in    addrSockSvr;

    struct    sockaddr_in    addrSockclt;

    long    nRet;

    BOOL    bValid = 1;


    char    szBuf[2048];

    char    szInBuf[2048];


    // 윈속 초기화

    if(WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)

    {

        return 1;

    }


    // 소켓 만들기

    sockSvr = socket(AF_INET, SOCK_STREAM, 0);

    if(sockSvr == INVALID_SOCKET)

    {

        printf("Socket Error No : %d", WSAGetLastError());

        return 1;

    }


    // 소켓 설정

    addrSockSvr.sin_family = AF_INET;

    addrSockSvr.sin_port = htons(333);

    addrSockSvr.sin_addr.S_un.S_addr = INADDR_ANY;


    // 소켓 옵션 설정

    setsockopt(sockSvr, SOL_SOCKET, SO_REUSEADDR, (const char *)&bValid, sizeof(bValid));


    if(bind(sockSvr, (struct sockaddr *)&addrSockSvr, sizeof(addrSockSvr)) != 0)

    {

        printf("Bind Error No : %d", WSAGetLastError());

        return 1;

    }


    // TCP클라이언트로 부터 접속 요구를 대기

    if(listen(sockSvr, 5) != 0)

    {

        printf("Listen Error No : %d", WSAGetLastError());

        return 1;

    }



    // 응답용 HTTP 메세지 작성

    memset(szBuf, 0, sizeof(szBuf));

    _snprintf(szBuf, sizeof(szBuf),

                "HTTP/1.0 200 OK\r\n"

                "Content-Length: 20\r\n"

                "Content-Type: text/html\r\n"

                "\r\n"

                "초간단 HTTP 서버\\n");


    while (1) {


        // TCP클라이언트로 부터 접속 요구 받기\tab   

        nlen = sizeof(addrSockclt);

        sockSS = accept(sockSvr, (struct sockaddr *)&addrSockclt, &nlen);


        if(sockSS == INVALID_SOCKET)

        {

            printf("Accept Error No : %d", WSAGetLastError());

            return 1;

        }



        memset(szInBuf, 0, sizeof(szInBuf));

        recv(sockSS, szInBuf, sizeof(szInBuf), 0);

        // 클라이언트로 받은 요구 처리 필요(여기서는 생략)

        printf("%s", szInBuf);


        // 클라이언트에 테스트용 HTTP 메세지 송신

        send(sockSS, szBuf, (int)strlen(szBuf), 0);


        closesocket(sockSS);

    }


    // 윈속 종료

    WSACleanup();


    return 0;


}
