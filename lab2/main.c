#include <stdio.h>
#include <stdbool.h>

// +(x,y)
unsigned int add(unsigned int x, unsigned int y) {
    return x + y;
}

// --(x,y)
unsigned int monus(unsigned int x, unsigned int y) {
    if (x <= y) return 0;
    return x - y;
}

// =(x,y) -> {T, F}
bool is_equal(unsigned int x, unsigned int y) {
    return x == y;
}

typedef struct {
    unsigned int div;
    unsigned int mod;
} DivModResult;

// 1. ДОБУТОК (Множення)
unsigned int product(unsigned int a, unsigned int b) {
    unsigned int res = 0;
    // Нам потрібен лічильник. Використовуємо b.
    // Поки b != 0, додаємо a до результату і віднімаємо 1 від b.
    
    // Примітка: "1" тут виступає як константа. Виконавець знає числа.
    while (!is_equal(b, 0)) {
        res = add(res, a);   // res = res + a
        b = monus(b, 1);     // b = b - 1
    }
    return res;
}

// 2. ЗАЛИШОК (Mod)
unsigned int mod(unsigned int a, unsigned int b) {
    if (is_equal(b, 0)) return 0; 

    while (is_equal(monus(b, a), 0)) {
        a = monus(a, b);        
        if (is_equal(a, 0)) break; 
    }
    return a;
}

// 3. ЦІЛА ЧАСТИНА (Div)
unsigned int div_op(unsigned int a, unsigned int b) {
    if (is_equal(b, 0)) return 0;

    unsigned int count = 0; 
    
    while (is_equal(monus(b, a), 0)) {
        a = monus(a, b);   
        count = add(count, 1);
        
        if (is_equal(a, 0)) break;
    }
    return count;
}

// 4. КОМПЛЕКСНЕ ДІЛЕННЯ <div, mod>
DivModResult div_mod(unsigned int a, unsigned int b) {
    DivModResult res;
    res.div = 0;
    res.mod = a; 
    
    if (is_equal(b, 0)) {
        res.mod = 0; 
        return res;
    }

    while (is_equal(monus(b, res.mod), 0)) {
        res.mod = monus(res.mod, b); 
        res.div = add(res.div, 1);  
        
        if (is_equal(res.mod, 0)) break;
    }
    
    return res;
}

int main() {
    unsigned int x = 13;
    unsigned int y = 4;

    printf("Operations with %u and %u:\n", x, y);
    
    // 1. Добуток
    printf("1. Product: %u * %u = %u\n", x, y, product(x, y));

    // 2. Mod
    printf("2. Mod: %u %% %u = %u\n", x, y, mod(x, y));

    // 3. Div
    printf("3. Div: %u / %u = %u\n", x, y, div_op(x, y));

    // 4. DivMod Pair
    DivModResult dm = div_mod(x, y);
    printf("4. Pair <Div, Mod>: <%u, %u>\n", dm.div, dm.mod);

    return 0;
}