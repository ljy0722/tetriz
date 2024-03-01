#include "draw.h"
#include "terminal.h"
#include <iostream>

/*
    
*/

namespace dw{
    inline int block2col(int b)
    {
        return 2 * b - 1;
    }
    void window(int top, int left, int width, int height, std::string title)
    {
        tc::move_to(top,block2col(left));
        for (int i = 0; i < height;i++){
            tc::move_to(top + i, block2col(left));
            for (int j = 0; j < width; j++)
            {
                if(i==0){
                    if(j==0){
                        std::cout << " ┌";
                    }
                    else if(j==width-1){
                        std::cout << "┐";
                    }
                    else{
                        std::cout << "──";
                    }
                }
                else if(i==height-1){
                    if(j==0){
                        std::cout << " └";
                    }
                    else if(j==width-1){
                        std::cout << "┘";
                    }
                    else{
                        std::cout << "──";
                    }
                }
                else{
                    if(j==0){
                        std::cout << " │";
                    }
                    else if(j==width-1){
                        std::cout << "│";
                    }
                    else{
                        std::cout << "  ";
                    }
                }
            }
        }
        tc::move_to(top, block2col(left) + (width * 2 - title.length()) / 2);
        std::cout << title;
    }
}