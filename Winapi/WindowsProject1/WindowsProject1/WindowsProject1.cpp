// WindowsProject1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "WindowsProject1.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    //HINSTANCE hInstance - 윈도우가 응용프로그램에게 주는 고유번호(인증번호). 앞에 h는 Handle 약어.
    //LPWSTR - 

    //경고오류 해제시키기위한 윈도우의 편파
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    // hInstance - 내가 윈도우에게 받은 프로그램 고유번호. szTitle - 윈도우가 나에게 주는 이 프로그램이름
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING); // 띄워주는 윈도우창의 이름을 szTitle로설정
    LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    //단축키를 사용하기 위하 핸들
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0)) //윈도우에 어떤 변화가 생기는지 감지하는 함수.
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) //윈도우의 단축키 처리. 단축키를 누르지 않으면 일반적인 msg 처리.ㅈ
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//  윈도우창 띄우기 전에 사전에 필요한 정보를 등록해주는 함수. 윈도우창 크기 늘였다 줄였다 등등의 설정
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW; //창크기 바꾸면 다시 창 그리기
    wcex.lpfnWndProc    = WndProc; //윈도우 상태에 이상발생시 어떤 행동(함수)해줌, 함수포인터
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance; //이 윈도우 클래스를 등록하려는 응용프로그램의 고유번호

    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1)); //윈도우 창의 아이콘
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW); //윈도우 창의 커서. IDC_CROSS로 바꿔서 해보기
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1); //윈도우창의 색깔.

    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1); //메뉴이름. nullptr로 바꿔서 실행해서 비교해보기
    wcex.lpszClassName  = szWindowClass; //이 윈도우 클래스 형식의 이름. 윈도우 창 만들때 선택할수 있는 형식을 szWindowClass안에 들어있는 문자열 이름으로 등록하는 것
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   //윈도우 만들어 주는 함수. 2개고 3개고 가능.
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   HWND hWnd0 = CreateWindowW
   (
       szWindowClass,  //윈도우 창의 형식.
       szTitle,         //윈도우 창의 제목
       WS_OVERLAPPEDWINDOW, //윈도우 스타일
       CW_USEDEFAULT, // 시작 x좌표. 아무 정수로 바꿔도 됨 한번 해보기
       0, // 시작 Y좌표
       CW_USEDEFAULT, //끝 x좌표
       0, //끝 Y좌표
       nullptr, 
       nullptr, 
       hInstance, //창을 만드려는 응용프로그램 고유번호
       nullptr
   );

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);  //윈도우창 hWnd 화면에 보여주기
   UpdateWindow(hWnd);          //윈도우창 hWnd 다시그리기

   ShowWindow(hWnd0, nCmdShow);  //윈도우창 hWnd 화면에 보여주기

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) //윈도우 프록시 함수. 윈도우에 무슨일이 생기면 호출되는 함수이다.
{
    //hwnd의 역할 - 어떤 윈도우에 메세지가 왔는지 알려줌

    //message - 윈도우에서 발생한 현상의 종류 (윈도우크기가 바뀜, 윈도우가 선택됨 등등)
    //LPARAM, WPARAM => message에 대응하는 추가 정보. 필요할수도 아닐수도있음
    switch (message)
    {

    case WM_CREATE:  //윈도우 창 만들어질때 어떤 행동을 해라
    {

    }
    case WM_COMMAND: //WM == 윈도우 메세지
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            //hdc - 윈도우에 뭔가를 그리기위한 권한. 다시말해, hWnd라는 윈도우에 그리기 위한 권한.

            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0); //GetMassage 함수에 0을 리턴해게 해서 while문을 빠져나가게 만든다.
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam); //사용자가 따로 정의 안해주면 윈도우의 기본 설정으로 처리한다
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
