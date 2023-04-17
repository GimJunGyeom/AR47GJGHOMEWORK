#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>

// ù��° �����Դϴ�.
// ������ �÷��̾��� ��ź�� ������ �����ϰ� �ϼ���.

class ConsoleGameScreen;
class Item : public ConsoleGameObject
{
public:
	// constrcuter destructer
	Item();
	~Item();

	// delete Function
	Item(const Item& _Other) = delete;
	Item(Item&& _Other) noexcept = delete;
	Item& operator=(const Item& _Other) = delete;
	Item& operator=(Item&& _Other) noexcept = delete;

	static void SetCreateNewItemTrue()
	{
		CreateNewItem = true;
	}
	static void SetCreateNewItemfalse()
	{
		CreateNewItem = false;
	}
	static bool GetCreateNewItem()
	{
		return CreateNewItem;
	}

protected:
	void Update() override;

private:
	static bool CreateNewItem;
};

