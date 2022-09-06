// STACK.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


 class Stack {
private:
    class Node {
    private:
        int data;
        Node* under;

    public:
        Node(int data,Node* node) {
            this->data = data;
            under = node;
        }
        Node* getUnder() {
            return under;
     }
        int getData() {
            return data;
        }
        
    };
    Node* atTop = nullptr;
    Node* atTopMinimal = nullptr;
public:
    bool isEmpty() {
        return atTop == nullptr;
    }
    void push(int data)
    {
        if (atTop == nullptr) {
            atTopMinimal = new Node(data, nullptr);
            atTop = new Node(data, nullptr);
        }
        else if(atTopMinimal->getData() > data)
        {
            atTopMinimal = new Node(data, atTopMinimal);
            atTop = new Node(data, atTop);
        }
        else {
            atTop = new Node(data, atTop);
        }

        
    }
    int peek() {
        return atTop->getData();
    }
    int pop() {
        if (atTop == nullptr)
            return 0;
        if (atTop->getData() == atTopMinimal->getData())
        {
            Node* toDelete1 = atTopMinimal;
            atTopMinimal = atTopMinimal->getUnder();
            delete toDelete1;
        }
        int data = atTop->getData();
        Node* toDelete = atTop;
        atTop = atTop->getUnder();
        delete toDelete;
        return data;
    }
    int min() {
        if (atTopMinimal == nullptr)
            return 0;
        return atTopMinimal->getData();
    }
};

int main()
{
    Stack myStack;
    Stack minimal;
    myStack.push(8);
    std::cout << myStack.min()<<std::endl;
    myStack.push(6);
    myStack.push(5);
    std::cout << myStack.min()<<std::endl;
    myStack.push(9);
    myStack.pop();
    std::cout << myStack.min() << std::endl;
    myStack.pop();
    std::cout << myStack.min() << std::endl;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
