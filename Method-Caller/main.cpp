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
        return 0;
    }
    
    //ifstream in (argv[1]);
    
    return 0;
}

