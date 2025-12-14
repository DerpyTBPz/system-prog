#include <stdio.h>
#include <stdbool.h>

// s(x) = x + 1
unsigned int s(unsigned int x) 
{
    return x + 1;
}

// p(x) = x - 1
unsigned int p(unsigned int x) 
{
    if (x == 0) 
        return 0; 
    return x - 1;
}

// =(x,y) -> {T, F}
bool is_equal(unsigned int x, unsigned int y) 
{
    return x == y;
}

// sum (m + n)
unsigned int sum(unsigned int m, unsigned int n) 
{
    while (!is_equal(n, 0)) {
        m = s(m);
        n = p(n);
    }
    return m;
}

// Diff (m - n)
unsigned int diff(unsigned int m, unsigned int n) 
{
    while (!is_equal(n, 0)) 
    {
        if (is_equal(m, 0)) 
            return 0;
        m = p(m);
        n = p(n);
    }
    return m;
}

// m mod n
unsigned int mod(unsigned int m, unsigned int n) {
    if (is_equal(n, 0)) return 0; 
    
    while (is_equal(diff(n, m), 0)) 
    {
        m = diff(m, n);
        
        if (is_equal(m, 0) && !is_equal(n, 0)) 
            return 0; 
        if (is_equal(m, 0)) 
            break; 
    }
    return m;
}

// NZD(a, b) = NZD(b, a % b)
unsigned int gcd(unsigned int m, unsigned int n) 
{
    while (!is_equal(n, 0)) 
    {
        unsigned int temp = n;
        n = mod(m, n);
        m = temp;
    }
    return m;
}

int main() {
    unsigned int a = 15;
    unsigned int b = 4;
    unsigned int c = 12;

    printf("--- Test Level 1 ---\n");
    printf("Sum(%u, %u) = %u\n", a, b, sum(a, b));    
    printf("Diff(%u, %u) = %u\n", a, b, diff(a, b));  
    printf("Diff(%u, %u) = %u\n", b, a, diff(b, a));   

    printf("\n--- Test Level 2 ---\n");
    printf("Mod(%u, %u) = %u\n", a, b, mod(a, b));  
    printf("Mod(20, 5) = %u\n", mod(20, 5));  

    printf("\n--- Test Level 3 ---\n");
    printf("GCD(12, 18) = %u\n", gcd(12, 18));  
    printf("GCD(100, 25) = %u\n", gcd(100, 25));   
    printf("GCD(7, 13) = %u\n", gcd(7, 13)); 

    return 0;
}