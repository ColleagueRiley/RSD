#include <fstream>

std::string readFile(std::string file){
   std::string output, line;
   std::ifstream rfile(file); // read the file into rfile

   while (std::getline (rfile,line)) // read the file line by line
      output += line + '\n'; // add teh line to the output

   rfile.close(); // close the file   
   return output;
}

int main(){
   std::string nFile, line; // new file and next line
   std::ifstream rfile("RSD.hpp"); // read the file into rfile

   while (std::getline (rfile, line)){ // read the file line by line
       if (line.find("#include \"include/") < line.size()){
         // get the header name
         std::string header = line;
	 header.replace(header.begin(), header.begin() + 10, "");
         header.replace(header.end()-1, header.end(), "");
         
         line = readFile(header); // set the line to content of the header file
      }
      
      nFile += line + '\n'; // add teh line to the output
   }

   rfile.close(); // close the file   

   // write the new file into "RSD"
   FILE* f = fopen("RSD","w+"); // open RSD file
   
   fwrite(nFile.c_str(), nFile.size(), 1, f);
   
   fclose(f); // close the file
}
