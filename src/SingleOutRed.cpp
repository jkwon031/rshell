#ifndef __SINGLEOUTRED_CPP__
#define __SINGLEOUTRED_CPP__

#include "Connector.h"
#include "SingleOutRed.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
#include <fcntl.h>

using namespace std;

SingleOutRed::SingleOutRed(Base* lhs, Base* rhs): Connector(lhs,rhs) {}
SingleOutRed::SingleOutRed(): Connector() {}

bool SingleOutRed::execute(int in, int out) {
    string outfile = rhs->get_data();
    out = open(outfile.c_str(),O_WRONLY| O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    if(dup2(out,1) == -1) {
        perror("dup2");
        return false;
    }

    return lhs->execute(in,out);
}


#endif