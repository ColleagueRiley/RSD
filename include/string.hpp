struct string{
    // data functions

    int size(); // gets the size of the string
    char* c_str(); // generates a char* and returns it

    // init functions
    string(){}
    string(void* c);
    string(void** s);
    
    string(const void* c) { string((void*)c); }
    string(const void** s) { string((void**)s); }
   
    private:
        linkedList data;
                
};
#ifdef RSDSOURCE
string::string(void* c){
    data.data = c; // set the first member of the data linked list to be the single init data
}

string::string(void** s){
    linkedList* output; // output linked list
    
    for (int i=0; i < sizeof(s); i++){ // go through each member of the array 
        output->data = s[i]; // add to output's data
        output = output->next; // move to the next piece of data
    }
    
    // return to root data
    while (output->prev != NULL) output = output->prev;

    data = *output; // set the current data to the newly made output data
}


int string::size(){
    int s = 0; 
    linkedList ll = data; // linked list for getting the chars
    
    while (ll.data != NULL){
        s++;
        ll = *ll.next; // switch to next data
    }

    return s;
}


char* string::c_str(){
    char* output; // char* to output
    linkedList ll = data; // linked list for getting the chars
    
    while (ll.data != NULL){
        output += *(char*)ll.data; // get the data
        ll = *ll.next; // switch to next data
    }

    return output;
}

#endif