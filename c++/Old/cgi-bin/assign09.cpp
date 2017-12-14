/**************************************************************************
*  Assign09 will compute the montly mortgage payment based on user
*  givein input
*  
*  M = loan_amount [ apr(1 + apr)^loan_term ] / [ (1 + apr)^loan_term – 1]
**************************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include <stdio.h>

int main()
{  
   char* query = getenv("QUERY_STRING");
   float apr            = 0;
   float loanTerm       = 0;
   float loanAmount     = 0;
   float mortgageAmount = 0.0;
   sscanf(query, "apr=%f&loanTerm=%f&loanAmount=%f", &apr, &loanTerm, &loanAmount);
 
   apr = (apr / 100) / 12;
   loanTerm = loanTerm * 12;
   
   std::cout.setf(std::ios::fixed);
   std::cout.setf(std::ios::showpoint);
   std::cout.precision(2);
   
   mortgageAmount = loanAmount * (apr * ((std::pow(1 + apr, loanTerm)) / (std::pow(1 + apr, loanTerm) - 1)));
  
   std::cout<< "Content-type: text/html\n\n"
            << "<html><head><style>body{margin:auto;font-family:papyrus;text-align:center;}"
            << "div{background-color:lightcyan;margin:10em 10em;border-radius:5em; padding:3em 0 3em 1em;}"
            << "table{font-size:200%; margin: 0 10em;}"
            << "span{font-size:150%;color:red;}"
            << "h1{font-size:300%;margin:0;}</style>"
            << "</head><body><div><h1>" 
            << "Your Monthly Payment Is:</h1><br/>"
            << "<table><tr><td>APR: <span>" << apr * 1200 << "%</span></td></tr><br/>"
            << "<tr><td>Loan Term: <span>" << loanTerm / 12 << " yrs</span></td></tr><br/>"
            << "<tr><td>Loan Amount: <span>$" << loanAmount << "</span></td></tr><br/>"
            << "<tr><td>Mortgate Amount: <span>$" << mortgageAmount << "</span></td></tr></table>"
            << "</div></body></html>";
   
   return 0;
}