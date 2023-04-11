#include <Windows.h>
#include <assert.h>

typedef void(*func)();
using func = void(*)();


#define MsgAssert(_Text) MessageBoxA(nullptr, _Text, "제목", MB_OK); assert(false);

int main()
{
	/*MessageBoxA(nullptr, "Text", "Title", MB_OK);
	assert(false);*/

	MsgAssert("ㅕㅕ");
	return 0;
}