#include <iostream>
#include "Board.hpp"
#include <stdexcept>
#include <string>

using namespace std;
using namespace ariel;

void ariel::Board::post(unsigned int row, unsigned int clm, Direction direct, string msg) {

    if(msg.length() > Board::longest)
    {
        Board::longest = msg.length();
    }
    switch(direct)
    {
        case Direction::Vertical:
            for(unsigned int i=0 ; i<msg.length() ; i++)
            {
                Board::b[row + i][clm] = msg[i]; 
            }
            break;
        case Direction::Horizontal:
            for(unsigned int i=0 ; i<msg.length() ; i++)
            {
                Board::b[row][clm + i] = msg[i];
            }
            break;
    }

}

string ariel::Board::read(unsigned int row, unsigned int clm, Direction direct,unsigned int length) {

    if(length == 0)
    {
        return "";
    }
    string msg;
    switch(direct)
    {
        case Direction::Vertical:
            for(unsigned int i=0 ; i<length ; i++)
            {
                if(Board::b[row + i][clm] == '\0')
                {
                    msg += '_';
                }
                else
                {
                    msg += Board::b[row +i][clm];
                }
            }
            break;
        case Direction::Horizontal:
            for(unsigned int i=0 ; i<length ; i++)
            {
                if(Board::b[row][clm + i] == '\0')
                {
                    msg += '_';
                }
                else
                {
                    msg += Board::b[row][clm + i];
                }
            }
            break;
    }
    return msg;

}

void ariel::Board::show() {

    int rows_size = Board::b.size();
    int clms_size = 1;
    for(map<unsigned int, map<unsigned int, char>>::iterator it=Board::b.begin() ; it!=Board::b.end() ; it++)
    {
        if(it->second.size() > clms_size)
        {
            clms_size = it->second.size();
        }
    }
    char ans[rows_size][clms_size];
    for(int i=0 ; i < rows_size ; i++)
    {
        for(int j=0 ; j < clms_size ; j++)
        {
            ans[i][j] = '_';
        }
    }
    int i = 0;
    int j = 0;
    unsigned int row = 0;
    unsigned int clm = 0;
    for(map<unsigned int, map<unsigned int, char>>::iterator it=Board::b.begin() ; it!=Board::b.end() ; it++)
    {
        row = it->first;
        for(map<unsigned int, char>::iterator iter=it->second.begin() ; iter!=it->second.end() ; iter++)
        {
            clm = iter->first;
            if(Board::b[row][clm] != '\0' && ans[i][j] == '_')
            {
                ans[i][j] = iter->second;
                if(i<(rows_size-1))
                {
                    it++;
                    if(Board::b[it->first][clm] != '\0')
                    {
                        ans[i+1][j] = Board::b[it->first][clm];
                    }
                    it--;
                }    
            }
            j++;
        }
        j = 0;
        i++;
    }
    for(int i=0 ; i < rows_size ; i++)
    {
        for(int j=0 ; j < clms_size ; j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
}

