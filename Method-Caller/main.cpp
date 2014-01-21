//
//  main.cpp
//  Method-Caller
//
//  Created by Jake Gregg on 1/21/14.
//  Copyright (c) 2014 Parallel and Cloud Computing laboratory. All rights reserved.
//

#include <iostream>
#include <dlfcn.h>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[])
{

    // insert code here...
    if (argc < 3) {
        cout << "Invalid number of args. Need filename and method." << endl;
        return 1;
    }
    
    cout << "Importing " << argv[1] << "...." << endl;
    void* handle = dlopen(argv[1], RTLD_LAZY);
    if (!handle) {
        cerr << "Cannot open file : " << dlerror() << endl;
        return 1;
    }
    
    cout << "Loading symbol " << argv[2] << "..." << endl;
    typedef void (*method_t)();
    
    // reset errors
    dlerror();
    method_t method = (method_t) dlsym(handle, argv[2]);
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        cerr << "Cannot load symbol " << argv[2] << ": " << dlsym_error << endl;
        dlclose(handle);
        return 1;
    }
    
    cout << "Performing method " << argv[2] << "..." << endl;
    method();
    cout << "Closing lib..." << endl;
    dlclose(handle);
    
    return 0;
}

