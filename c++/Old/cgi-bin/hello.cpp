/********************************
 * Server side c++ test
 *******************************/
 #include <iostream>

int main()
{
   std::cout << "Content-type: text/html\n\n"
             << "<html><body><h1>Hello World</h1></body></html>"
             << std::endl;
   return 0;
}
