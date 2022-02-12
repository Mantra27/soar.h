#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>

using namespace std;

string get(string cmd, string type) {
      
   string command = "node get.js {}headerisoverhere{} " + cmd + " " + type;
   char buffer[128];
   string result = "";
   
   // Open pipe to file
   FILE* pipe = popen(command.c_str(), "r");
   
   if (!pipe) {
      return "popen failed!";
   }

   // read till end of process:
   while (!feof(pipe)) {

      // use buffer to read and add to result
      if (fgets(buffer, 128, pipe) != NULL)
         result += buffer;
   }

   pclose(pipe);

//    if(result == "404"){
//       throw std::invalid_argument("AddPositiveIntegers arguments must be positive");
//    }

    return result;
  
};

string post(string url, string body, string type) {
      
   string command = "node post.js {}headerisoverhere{} " + url + " " + "\"" + body + "\" " + type;

   char buffer[128];
   string result = "";
   
   // Open pipe to file
   FILE* pipe = popen(command.c_str(), "r");
   
   if (!pipe) {
      return "popen failed!";
   }

   // read till end of process:
   while (!feof(pipe)) {

      // use buffer to read and add to result
      if (fgets(buffer, 128, pipe) != NULL)
         result += buffer;
   }

   pclose(pipe);

//    if(result == "404"){
//       throw std::invalid_argument("AddPositiveIntegers arguments must be positive");
//    }

  return result;
}