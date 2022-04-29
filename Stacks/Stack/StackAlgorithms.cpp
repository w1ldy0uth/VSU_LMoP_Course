/* 10 вопрос, проверка скобок */
void parenthesesVerification(string term) {
    TStack s;
    init(s);
    bool flag = false;
    for (int i = 0; i < term.length(); i++) {
        if (term[i] == '(' || term[i] == '[')
            push(s, term[i]);
        else if (!isEmpty(s) && ((term[i] == ')' && peek(s) == '(') || (term[i] == ']' && peek(s) == '[')))
            pop(s);
        else
            flag = true;
    }
    if (!isEmpty(s))
        flag = true;
    if (flag)
        cout << "Скобки не сбалансированы\n";
    else
        cout << "Скобки сбалансированы\n";
}


/* 11 вопрос, перевод выражения из инфиксной нотации в постфиксную (обратную польскую) */
string infixToPostfix(string inf) {
    TStack s;
    init(s);                                      // в гробу я уже видел эти алгоритмы и структуры данных, надо было реально на ргф идти учиться
    string postfix
    for (int i= 0; i < inf.length(); i++) {
        if ((inf[i] >= 'a' && inf[i] <= 'z') || (inf[i] >= 'A' && inf[i] <= 'Z') || (inf[i] >= '0' && inf[i] <= '9'))
            postfix += inf[i];
        else if (inf[i] == '(')
            push(s, inf[i]);
        else if (inf[i] == '(') {
            while ((peek(s) != '(') && (!isEmpty(s))) {
                postfix += peek(s);
                pop(s);
            }
            if (peek(s) == '(')
                pop(s);
        }
        else if (isOperator(inf[i])) {
            if(isEmpty(s))
                push(s, i);
            else {
                if (checkOperator(inf[i]) > checkOperator(peek(s)))
                    push(s, inf[i]);
                else {
                    while ((!isEmpty(s)) && (checkOperator(inf[i]) <= checkOperator(peek(s)))) {
                        postfix += peek(s);
                        pop(s);
                    }
                    push(s, inf[i]);
                }
            }
        }
    }
    while (!isEmpty(s)) {
        postfix += peek(s);
        pop(s);
    }
    return postfix;
}

bool isOperator(char op) {
    return (op == '+' || op == '-' || op == '*');
}

int checkOperator(char op) {
    int priority;
    if (op == '*')
        priority = 2;
    else if (op == '+' || op == '-')
        priority = 1;
    else
        priority = -1;
    return priority;
}


/* 12 вопрос, вычисление выражения */
int getTermValue(string postfix) {
    TStack(s);
    init(s);
    int x, y;
    for (int i = 0; i < postfix.length(); i++) {
        if (postfix[i] >= '0' && postfix[i] <= '9')
            push(s, postfix[i] - '0');
        else {
            y = peek(s);
            pop(s);
            x = peek(s);
            pop(s);
            int res = calc(x, y, postfix[i]);
            push(s, res);
        }
    }
    return peek(s);
}

int calc(int x, int y, char op) {
    int res = 0;
    switch (op) {
        case '+':
            res = x + y;
            break;
        case '-':
            res = x - y;
            break;
        case '*':
            res = x * y;
            break;
        case '/':
            res = x / y;
            break;
    }
    return res;
}
