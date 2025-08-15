#include <stdio.h>
#include <math.h>

void asci_check(void) {
    printf("       *\n"); 
    printf("      * \n");
    printf("     *  \n");
    printf("    *   \n");
    printf("   *    \n");
    printf("* *     \n");
    printf(" *      \n");
}

void sphere_vol(void) {
    float r;
    float pi = 3.14159;
    
    printf("Enter radius of sphere for volume: \n");
    scanf("%f", &r);
    
    float v = (4.0f/3.0f) * pi * (r*r*r);

    printf("%f\n", v);
}

void smallest_dollar_amt() {
    int total;
    int twenties = 0;
    int tens = 0;
    int fives = 0;
    int ones = 0;
    printf("Enter a dollar amount: ");
    scanf("%d", &total);
    
    twenties = total / 20;
    total = total % 20;
    tens = total / 10;
    total = total % 10;
    fives = total / 5;
    total = total % 5;
    ones = total;

    printf("Twenties: %d\n", twenties);
    printf("Tens: %d\n", tens);
    printf("Fives: %d\n", fives);
    printf("Ones: %d\n", ones);
}

void remaining_loan_balance(void) {
    float loan_amt = 0;
    float interest_rate = 0;
    float monthly_payment = 0;
    
    float payment_towards_principal = 0;

    printf("Enter total loan amount: ");
    scanf("%f", &loan_amt);
    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);
    
    interest_rate /= 100;
    
    float monthly_interest = (loan_amt * interest_rate) / 12;
    if (monthly_interest > monthly_payment) {
        fprintf(stderr,"Your monthly payment of $%.2f is less than your monthly interest payment of $%.2f\n", 
            monthly_payment, monthly_interest);
        return;
    }



    int payment = 0;
    while (loan_amt > 0) {
        monthly_interest = (loan_amt * interest_rate) / 12;
        payment_towards_principal = monthly_payment - monthly_interest;
        if (payment_towards_principal > loan_amt) {
            payment_towards_principal = loan_amt;
        }
        loan_amt -= payment_towards_principal;
        ++payment;
        
        
        printf("Balance remaining after %d payments: $%.2f\n", payment, loan_amt);
    }
}

int main(void) {
    // asci_check();
    // sphere_vol();
    // smallest_dollar_amt();
    remaining_loan_balance();

    return 0;
}