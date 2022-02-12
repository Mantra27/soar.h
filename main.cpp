#include <iostream>
#include "soar.h"
using namespace std;

int main(){
   string GETdata = get("http://localhost:8080", "text");
   string POSTdata = post("http://localhost:8080", "hello world", "json");

   cout << GETdata << endl << POSTdata;
}