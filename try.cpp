#include <string>
#include <vector>
#include <bitset>
#include <iostream>
#include <algorithm>
#include <utility>

#include <time.h>

using namespace std;

struct QmSolution 
{
    int numVar;
    vector<string> primes;
    vector<vector<string>> minimumSops;
};

QmSolution *solveQm(int numVar, vector<int> minterms, vector<int> dontcares, bool verbose)
{
    QmSolution *sol = new QmSolution;
    sol->numVar = numVar;
    vector<string> MIN(minterms.size());
    vector<string> DON(dontcares.size());
    vector<string> r0;
    vector<string> r1;
    vector<string> r2;
    vector<string> r3;
    vector<string> r4;
    vector<string> r5;
    vector<string> r6;
    vector<string> r7;
    vector<string> r8;
    vector<string> r9;
    vector<string> r10;
    vector<string> n0;
    vector<string> n1;
    vector<string> n2;
    vector<string> n3;
    vector<string> n4;
    vector<string> n5;
    vector<string> n6;
    vector<string> n7;
    vector<string> n8;
    vector<string> n9;
    vector<string> n10;
    vector<string> u0;
    vector<string> u1;
    vector<string> u2;
    vector<string> u3;
    vector<string> u4;
    vector<string> u5;
    vector<string> u6;
    vector<string> u7;
    vector<string> u8;
    vector<string> u9;
    vector<string> u10;
    vector<string> used;
    vector<string> unused;
    vector<string> newRound;
    static int n;

    //轉成二進制
    switch(numVar)
    {
    case 8:
        for (int i = 0; i < minterms.size(); i++)
        {
            bitset<8> binary(minterms[i]); 
            MIN.push_back(binary.to_string());
        }
        for (int i = 0; i < dontcares.size(); i++)
        {
            bitset<8> binary(dontcares[i]);
            DON.push_back(binary.to_string());
        }
        break;
    case 9:
        for (int i = 0; i < minterms.size(); i++)
        {
            bitset<9> binary(minterms[i]); 
            MIN.push_back(binary.to_string());   
        }
        for (int i = 0; i < dontcares.size(); i++)
        {
            bitset<9> binary(dontcares[i]);
            DON.push_back(binary.to_string());
        }
        break;
    case 10:
        for (int i = 0; i < minterms.size(); i++)
        {
            bitset<10> binary(minterms[i]); 
            MIN.push_back(binary.to_string());   
        }
        for (int i = 0; i < dontcares.size(); i++)
        {
            bitset<10> binary(dontcares[i]);
            DON.push_back(binary.to_string());
        }
        break;
    default:
        break;
    }
//================Round 1=================
    //數1的個數
    for (int i = 0; i < MIN.size(); i++)
    {
        int count = 0;
        for (const auto &c : MIN[i])
            if (c == '1')
                count++;
        switch (count)
        {
            case 0:
                r0.push_back(MIN[i]);
                break;
            case 1:
                r1.push_back(MIN[i]);
                break;
            case 2:
                r2.push_back(MIN[i]);
                break;
            case 3:
                r3.push_back(MIN[i]);
                break;
            case 4:
                r4.push_back(MIN[i]);
                break;
            case 5:
                r5.push_back(MIN[i]);
                break;
            case 6:
                r6.push_back(MIN[i]);
                break;
            case 7:
                r7.push_back(MIN[i]);
                break;
            case 8:
                r8.push_back(MIN[i]);
                break;
            case 9:
                r9.push_back(MIN[i]);
                break;
            case 10:
                r10.push_back(MIN[i]);
                break;
            default:
                break;
        }
    }
    for (int i = 0; i < DON.size(); i++)
    {
        int count = 0;
        for (const auto &c : DON[i])
            if (c == '1')
                count++;
        switch (count)
        {
            case 0:
                n0.push_back(DON[i]);
                break;
            case 1:
                n1.push_back(DON[i]);
                break;
            case 2:
                n2.push_back(DON[i]);
                break;
            case 3:
                n3.push_back(DON[i]);
                break;
            case 4:
                n4.push_back(DON[i]);
                break;
            case 5:
                n5.push_back(DON[i]);
                break;
            case 6:
                n6.push_back(DON[i]);
                break;
            case 7:
                n7.push_back(DON[i]);
                break;
            case 8:
                n8.push_back(DON[i]);
                break;
            case 9:
                n9.push_back(DON[i]);
                break;
            case 10:
                n10.push_back(DON[i]);
                break;
            default:
                break;
        }
    }

    //比較
    vector<vector<string>> rVectors = {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10};
    vector<vector<string>> nVectors = {n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10};
    vector<vector<string>> uVectors = {u0, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10};
    int numVectors = rVectors.size();

    /*for (int i = 0; i < numVectors; i++) 
    {
        for (int j = 0; j < nVectors[i].size(); j++)    
            cout<<nVectors[i][j]<<endl;
    }*/

    //min min 
    for (int i = 0; i < numVectors - 1; i++) 
    {
        if (rVectors[i].size() > 0 && rVectors[i+1].size() > 0)
        {
            for (int j = 0; j < rVectors[i].size(); j++) 
            {
                for (int k = 0; k < rVectors[i+1].size(); k++) 
                {
                    string diff = "";
                    for (int l = 0; l < rVectors[i][j].size(); l++) 
                    {
                        if (rVectors[i][j][l] == rVectors[i+1][k][l])
                            diff += rVectors[i][j][l];
                        else
                        {
                            diff += "-";
                        }    
                    }
                    int count = 0;
                    for (const auto& c : diff) 
                    {
                        if (c == '-')
                            count++;
                    }
                    if (count == 1)
                    {
                        newRound.push_back(diff);
                        used.push_back(rVectors[i][j]);
                        used.push_back(rVectors[i+1][k]);
                    }
                    else
                    {
                        unused.push_back(rVectors[i][j]);
                        unused.push_back(rVectors[i+1][k]);
                    }    
                }
            }
        }
    }
    //min don
    for (int i = 0; i < numVectors; i++) 
    {
        for (int j = 0; j < numVectors; j++)
        {
            if (rVectors[i].size() > 0 && nVectors[j].size() > 0)
            {
                for (int k = 0; k < rVectors[i].size(); k++) 
                {
                    for (int l = 0; l < nVectors[j].size(); l++) 
                    {
                        string diff = "";
                        for (int m = 0; m < rVectors[i][k].size(); m++) 
                        {
                            if (rVectors[i][k][m] == nVectors[j][l][m])
                                diff += rVectors[i][k][m];
                            else
                            {
                                diff += "-";
                            }    
                        }
                        int count = 0;
                        for (const auto& c : diff) 
                        {
                            if (c == '-')
                                count++;
                        }
                        if (count == 1)
                        {
                            newRound.push_back(diff);
                            used.push_back(rVectors[i][k]);
                        }
                        else
                        {
                            unused.push_back(rVectors[i][k]);
                        }    
                    }
                }
            }
        }
    }
    //don don
    for (int i = 0; i < numVectors - 1; i++) 
    {
        if (nVectors[i].size() > 0 && nVectors[i+1].size() > 0)
        {
            for (int j = 0; j < nVectors[i].size(); j++) 
            {
                for (int k = 0; k < nVectors[i+1].size(); k++) 
                {
                    string diff = "";
                    for (int l = 0; l < nVectors[i][j].size(); l++) 
                    {
                        if (nVectors[i][j][l] == nVectors[i+1][k][l])
                            diff += nVectors[i][j][l];
                        else
                        {
                            diff += "-";
                        }    
                    }
                    int count = 0;
                    for (const auto& c : diff) 
                    {
                        if (c == '-')
                            count++;
                    }
                    if (count == 1)
                    {
                        newRound.push_back(diff);
                    }
                    else
                    {

                    }    
                }
            }
        }
    }

    //清理
    std::sort(used.begin(), used.end());
    auto last1 = unique(used.begin(), used.end());
    used.erase(last1, used.end());
    std::sort(unused.begin(), unused.end());
    auto last2 = unique(unused.begin(), unused.end());
    unused.erase(last2, unused.end());
    std::vector<std::string> difference;
    std::set_difference(
        unused.begin(), unused.end(),
        used.begin(), used.end(),
        std::back_inserter(difference)
    );
    unused = difference;

    //數unused
    for (int i = 0; i < unused.size(); i++)
    {
        int count = 0;
        for (const auto &c : unused[i])
            if (c == '1')
                count++;
        switch (count)
        {
            case 0:
                u0.push_back(unused[i]);
                break;
            case 1:
                u1.push_back(unused[i]);
                break;
            case 2:
                u2.push_back(unused[i]);
                break;
            case 3:
                u3.push_back(unused[i]);
                break;
            case 4:
                u4.push_back(unused[i]);
                break;
            case 5:
                u5.push_back(unused[i]);
                break;
            case 6:
                u6.push_back(unused[i]);
                break;
            case 7:
                u7.push_back(unused[i]);
                break;
            case 8:
                u8.push_back(unused[i]);
                break;
            case 9:
                u9.push_back(unused[i]);
                break;
            case 10:
                u10.push_back(unused[i]);
                break;
            default:
                break;
        }
    }
    
    //清空r
    r0.clear();
    r1.clear();
    r2.clear();
    r3.clear();
    r4.clear();
    r5.clear();
    r6.clear();
    r7.clear();
    r8.clear();
    r9.clear();
    r10.clear();
    //數used
    for (int i = 0; i < used.size(); i++)
    {
        int count = 0;
        for (const auto &c : used[i])
            if (c == '1')
                count++;
        switch (count)
        {
            case 0:
                r0.push_back(used[i]);
                break;
            case 1:
                r1.push_back(used[i]);
                break;
            case 2:
                r2.push_back(used[i]);
                break;
            case 3:
                r3.push_back(used[i]);
                break;
            case 4:
                r4.push_back(used[i]);
                break;
            case 5:
                r5.push_back(used[i]);
                break;
            case 6:
                r6.push_back(used[i]);
                break;
            case 7:
                r7.push_back(used[i]);
                break;
            case 8:
                r8.push_back(used[i]);
                break;
            case 9:
                r9.push_back(used[i]);
                break;
            case 10:
                r10.push_back(used[i]);
                break;
            default:
                break;
        }
    }
    
    if (verbose)
    {
        std::cout <<"====================="<<endl;
        std::cout <<"Column "<<++n<<endl;
        std::cout <<"====================="<<endl;
        vector<vector<string>> rVec = {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10};
        vector<vector<string>> nVec = {n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10};
        vector<vector<string>> uVec = {u0, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10};
        for(int i = 0; i < rVec.size(); i++)
        {
            for(int j = 0; j < rVec[i].size(); j++)
            {
                if (rVec[i][j] == "")
                    rVec[i].erase(rVec[i].begin() + j);
            }
        }
        for(int i = 0; i < nVec.size(); i++)
        {
            for(int j = 0; j < nVec[i].size(); j++)
            {
                if (nVec[i][j] == "")
                    nVec[i].erase(nVec[i].begin() + j);
            }
        }
        for(int i = 0; i < uVec.size(); i++)
        {
            for(int j = 0; j < uVec[i].size(); j++)
            {
                if (uVec[i][j] == "")
                    uVec[i].erase(uVec[i].begin() + j);
            }
        }
        for (int i = 0; i < numVar+1; i++) 
        {
            if (rVec[i].size() > 0)
            {
                for (int j = 0; j < rVec[i].size(); j++)
                {
                    std::cout <<"v "<< rVec[i][j] << endl;
                }
            }
            if (nVec[i].size() > 0)
            {
                for (int j = 0; j < nVec[i].size(); j++)
                {
                    std::cout <<"d "<< nVec[i][j] << endl;
                }
            }
            if (uVec[i].size() > 0)
            {
                for (int j = 0; j < uVec[i].size(); j++)
                {
                    std::cout <<"  "<< uVec[i][j] << endl;
                }
            }
            if (rVec[i].size() > 0 || nVec[i].size() > 0 || uVec[i].size() > 0 )
                std::cout<<"---------------------"<<endl;
        }
    }
    
    /*for (int i = 0; i < newRound.size(); i++)
    {
        std::cout <<"  "<< newRound[i] << endl;
    }*/

//================Round2=================
    r0.clear();
    r1.clear();
    r2.clear();
    r3.clear();
    r4.clear();
    r5.clear();
    r6.clear();
    r7.clear();
    r8.clear();
    r9.clear();
    r10.clear();
    used.clear();
    unused.clear();

    //數1
    for (int i = 0; i < newRound.size(); i++)
    {
        int count = 0;
        for (const auto &c : newRound[i])
            if (c == '1')
                count++;
        switch (count)
        {
            case 0:
                r0.push_back(newRound[i]);
                break;
            case 1:
                r1.push_back(newRound[i]);
                break;
            case 2:
                r2.push_back(newRound[i]);
                break;
            case 3:
                r3.push_back(newRound[i]);
                break;
            case 4:
                r4.push_back(newRound[i]);
                break;
            case 5:
                r5.push_back(newRound[i]);
                break;
            case 6:
                r6.push_back(newRound[i]);
                break;
            case 7:
                r7.push_back(newRound[i]);
                break;
            case 8:
                r8.push_back(newRound[i]);
                break;
            case 9:
                r9.push_back(newRound[i]);
                break;
            default:
                break;
        }
    }
    newRound.clear();
    
    //比較
    vector<vector<string>> rVectors2 = {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9};
    numVectors = rVectors2.size();
    for (int i = 0; i < numVectors - 1; i++) 
    {
        if (rVectors2[i].size() > 0 && rVectors2[i+1].size() > 0)
        {
            for (int j = 0; j < rVectors2[i].size(); j++) 
            {
                for (int k = 0; k < rVectors2[i+1].size(); k++) 
                {
                    string diff = "";
                    for (int l = 0; l < rVectors2[i][j].size(); l++) 
                    {
                        if (rVectors2[i][j][l] == rVectors2[i+1][k][l])
                            diff += rVectors2[i][j][l];
                        else
                        {
                            diff += "-";
                        }    
                    }
                    int count = 0;
                    for (const auto& c : diff) 
                    {
                        if (c == '-')
                            count++;
                    }
                    if (count == 2)
                    {
                        newRound.push_back(diff);
                        used.push_back(rVectors2[i][j]);
                        used.push_back(rVectors2[i+1][k]);
                    }
                    else
                    {
                        unused.push_back(rVectors2[i][j]);
                        unused.push_back(rVectors2[i+1][k]);
                    }    
                }
            }
        }
    }

    //清理
    std::sort(newRound.begin(), newRound.end());
    auto lastt = unique(newRound.begin(), newRound.end());
    newRound.erase(lastt, newRound.end());
    std::sort(used.begin(), used.end());
    auto last3 = unique(used.begin(), used.end());
    used.erase(last3, used.end());
    std::sort(unused.begin(), unused.end());
    auto last4 = unique(unused.begin(), unused.end());
    unused.erase(last4, unused.end());
    std::vector<std::string> difference2;
    std::set_difference(
        unused.begin(), unused.end(),
        used.begin(), used.end(),
        std::back_inserter(difference2)
    );
    unused = difference2;

    //數unused
    for (int i = 0; i < unused.size(); i++)
    {
        int count = 0;
        for (const auto &c : unused[i])
            if (c == '1')
                count++;
        switch (count)
        {
            case 0:
                u0.push_back(unused[i]);
                break;
            case 1:
                u1.push_back(unused[i]);
                break;
            case 2:
                u2.push_back(unused[i]);
                break;
            case 3:
                u3.push_back(unused[i]);
                break;
            case 4:
                u4.push_back(unused[i]);
                break;
            case 5:
                u5.push_back(unused[i]);
                break;
            case 6:
                u6.push_back(unused[i]);
                break;
            case 7:
                u7.push_back(unused[i]);
                break;
            case 8:
                u8.push_back(unused[i]);
                break;
            case 9:
                u9.push_back(unused[i]);
                break;
            default:
                break;
        }
    }
    
    //清空r
    r0.clear();
    r1.clear();
    r2.clear();
    r3.clear();
    r4.clear();
    r5.clear();
    r6.clear();
    r7.clear();
    r8.clear();
    r9.clear();
    //數used
    for (int i = 0; i < used.size(); i++)
    {
        int count = 0;
        for (const auto &c : used[i])
            if (c == '1')
                count++;
        switch (count)
        {
            case 0:
                r0.push_back(used[i]);
                break;
            case 1:
                r1.push_back(used[i]);
                break;
            case 2:
                r2.push_back(used[i]);
                break;
            case 3:
                r3.push_back(used[i]);
                break;
            case 4:
                r4.push_back(used[i]);
                break;
            case 5:
                r5.push_back(used[i]);
                break;
            case 6:
                r6.push_back(used[i]);
                break;
            case 7:
                r7.push_back(used[i]);
                break;
            case 8:
                r8.push_back(used[i]);
                break;
            case 9:
                r9.push_back(used[i]);
                break;
            default:
                break;
        }
    }

    vector<string> pri;
    vector<vector<string>> sop;

    for (int i = 0; i < newRound.size(); i++)
    {
        string output = "";
        for (int j = 0; j < newRound[i].size(); j++)
        {
            if (newRound[i][j] == '0')
            {
                switch (j)
                {
                case 0:
                    output += "a'";
                    break;
                case 1:
                    output += "b'";
                    break;
                case 2:
                    output += "c'";
                    break;
                case 3:
                    output += "d'";
                    break;
                case 4:
                    output += "e'";
                    break;
                case 5:
                    output += "f'";
                    break;
                case 6:
                    output += "g'";
                    break;
                case 7:
                    output += "h'";
                    break;
                case 8:
                    output += "i'";
                    break;
                case 9:
                    output += "j'";
                    break;
                default:
                    break;
                }
            }  
            else if (newRound[i][j] == '1')
            {
                switch (j)
                {
                case 0:
                    output += "a";
                    break;
                case 1:
                    output += "b";
                    break;
                case 2:
                    output += "c";
                    break;
                case 3:
                    output += "d";
                    break;
                case 4:
                    output += "e";
                    break;
                case 5:
                    output += "f";
                    break;
                case 6:
                    output += "g";
                    break;
                case 7:
                    output += "h";
                    break;
                case 8:
                    output += "i";
                    break;
                case 9:
                    output += "j";
                    break;
                default:
                    break;
                }
            }
        }
        pri.push_back(output);
    }

    vector<string> t1;
    vector<string> t2;
    for (int i = 0; i < MIN.size(); i++) 
    {
        int count = 0;
        for (int j = 0; j < newRound.size(); j++) 
        {
            bool same_digits = true;
            for (int k = 0; k < newRound[j].size(); k++) 
            {
                if (newRound[j][k] != '-' && newRound[j][k] != MIN[i][k]) 
                {
                    same_digits = false;
                    break;
                }
            }
            if (same_digits) 
            {
                count++;
            }
        }
        if (count == 1)
        {
            for (int j = 0; j < newRound.size(); j++) 
            {
                bool same = true;
                for (int k = 0; k < newRound[j].size(); k++) 
                {
                    if (newRound[j][k] != '-' && newRound[j][k] != MIN[i][k]) 
                    {
                        same = false;
                        break;
                    }
                }
                if (same) 
                {
                    t1.push_back(newRound[j]);
                }
            }
        }
    }

    std::sort(t1.begin(), t1.end());
    auto last7 = unique(t1.begin(), t1.end());
    t1.erase(last7, t1.end());

    vector<string> non;
    for (int i = 0; i < MIN.size(); i++) 
    {
        bool have = false;
        for (int j = 0; j < t1.size(); j++) 
        {
            bool same_digits = true;
            for (int k = 0; k < t1[j].size(); k++) 
            {
                if (t1[j][k] != '-' && t1[j][k] != MIN[i][k]) 
                {
                    same_digits = false;
                    break;
                }
            }
            if (same_digits) 
            {
                have = true;
                break;
            }
        }
        if(!have)
        {
            non.push_back(MIN[i]);
        }
    }
    
    for (int i = 0; i < non.size(); i++) 
    {
        bool complete = false;
        for (int j = 0; j < newRound.size(); j++) 
        {
            bool same = true;
            for (int k = 0; k < newRound[j].size(); k++) 
            {
                if (newRound[j][k] != '-' && newRound[j][k] != non[i][k]) 
                {
                    same = false;
                    break;
                }
            }
            if (same)
            {
                bool found = false;
                for (int k = 0; k < non.size(); k++) 
                {
                    if (k != i) 
                    {
                        bool submatch = true;
                        for (int l = 0; l < newRound[j].size(); l++) 
                        {
                            if (newRound[j][l] != '-' && newRound[j][l] != non[k][l]) 
                            {
                                submatch = false;
                                break;
                            }
                        }
                        if (submatch) 
                        {
                            found = true;
                            break;
                        }
                    }
                }
                if (found) 
                {
                    t2.push_back(newRound[j]);
                    complete = true;
                    break;
                }
            }
        }
        if (!complete)
        {
            vector<string> r8s;
            for (int j = 0; j < newRound.size(); j++) 
            {
                bool same = true;
                for (int k = 0; k < newRound[j].size(); k++) 
                {
                    if (newRound[j][k] != '-' && newRound[j][k] != non[i][k]) 
                    {
                        same = false;
                        break;
                    }
                }
                if (same)
                {
                    r8s.push_back(newRound[j]);
                }
            }
            vector<int> count(r8s.size(), 0);
            for (int i = 0; i < r8s.size(); i++)
            {
                count[i] = 0;
                for (int j = 0; j < r8s[i].size(); j++)
                {
                    if (r8s[i][j] == '-')
                        count[i]++;
                }  
            }
            int max_value = 0;  
            int max_index = -1;  
            for (int i = 0; i < count.size(); i++) 
            {
                if (count[i] > max_value) 
                {
                    max_value = count[i];  
                    max_index = i;  
                }
            }
            if (max_index >= 0 && max_index < r8s.size()) {
                t2.push_back(r8s[max_index]);
            }
        }
    }
            
    std::sort(t2.begin(), t2.end());
    auto last888 = unique(t2.begin(), t2.end());
    t2.erase(last888, t2.end());
    t2.erase(remove(t2.begin(), t2.end(), ""), t2.end());

    vector<string> hold;
    for (int i = 0; i < t2.size(); i++)
    {
        string output = "";
        for (int j = 0; j < t2[i].size(); j++)
        {
            if (t2[i][j] == '0')
            {
                switch (j)
                {
                case 0:
                    output += "a'";
                    break;
                case 1:
                    output += "b'";
                    break;
                case 2:
                    output += "c'";
                    break;
                case 3:
                    output += "d'";
                    break;
                case 4:
                    output += "e'";
                    break;
                case 5:
                    output += "f'";
                    break;
                case 6:
                    output += "g'";
                    break;
                case 7:
                    output += "h'";
                    break;
                case 8:
                    output += "i'";
                    break;
                case 9:
                    output += "j'";
                    break;
                default:
                    break;
                }
            }  
            else if (t2[i][j] == '1')
            {
                switch (j)
                {
                case 0:
                    output += "a";
                    break;
                case 1:
                    output += "b";
                    break;
                case 2:
                    output += "c";
                    break;
                case 3:
                    output += "d";
                    break;
                 case 4:
                    output += "e";
                    break;
                case 5:
                    output += "f";
                    break;
                case 6:
                    output += "g";
                    break;
                case 7:
                    output += "h";
                    break;
                case 8:
                    output += "i";
                    break;
                case 9:
                    output += "j";
                    break;
                default:
                    break;
                }
            }
        }
        hold.push_back(output);
    }
    sop.push_back(hold);

    for (int i = 0; i < t1.size(); i++)
    {
        std::cout <<"  "<< t1[i] << endl;
    }
    for (int i = 0; i < t2.size(); i++)
    {
        //std::cout <<"  "<< t2[i] << endl;
    }

    for (int i = 0; i < pri.size(); i++)
        sol->primes.push_back(pri[i]);
    for (int i = 0; i < sop.size(); i++)
        sol->minimumSops.push_back(sop[i]);

 
    if (verbose)
    {
        std::cout <<"====================="<<endl;
        std::cout <<"Column "<<++n<<endl;
        std::cout <<"====================="<<endl;
        vector<vector<string>> rVec = {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9};
        vector<vector<string>> uVec = {u0, u1, u2, u3, u4, u5, u6, u7, u8, u9};
        for(int i = 0; i < rVec.size(); i++)
        {
            for(int j = 0; j < rVec[i].size(); j++)
            {
                if (rVec[i][j] == "")
                    rVec[i].erase(rVec[i].begin() + j);
            }
        }
        for(int i = 0; i < uVec.size(); i++)
        {
            for(int j = 0; j < uVec[i].size(); j++)
            {
                if (uVec[i][j] == "")
                    uVec[i].erase(uVec[i].begin() + j);
            }
        }
        for (int i = 0; i < numVar; i++) 
        {
            if (rVec[i].size() > 0)
            {
                for (int j = 0; j < rVec[i].size(); j++)
                {
                    std::cout <<"v "<< rVec[i][j] << endl;
                }
            }
            if (uVec[i].size() > 0)
            {
                for (int j = 0; j < uVec[i].size(); j++)
                {
                    std::cout <<"  "<< uVec[i][j] << endl;
                }
            }
            if (rVec[i].size() > 0 || uVec[i].size() > 0 )
                std::cout<<"---------------------"<<endl;
        }
    }
    /*for (int i = 0; i < newRound.size(); i++)
    {
        std::cout <<"  "<< newRound[i] << endl;
    }*/
/*
//================Round3=================
    r0.clear();
    r1.clear();
    r2.clear();
    r3.clear();
    r4.clear();
    r5.clear();
    r6.clear();
    r7.clear();
    r8.clear();
    r9.clear();
    r10.clear();
    used.clear();
    unused.clear();

    //數1
    for (int i = 0; i < newRound.size(); i++)
    {
        int count = 0;
        for (const auto &c : newRound[i])
            if (c == '1')
                count++;
        switch (count)
        {
            case 0:
                r0.push_back(newRound[i]);
                break;
            case 1:
                r1.push_back(newRound[i]);
                break;
            case 2:
                r2.push_back(newRound[i]);
                break;
            case 3:
                r3.push_back(newRound[i]);
                break;
            case 4:
                r4.push_back(newRound[i]);
                break;
            case 5:
                r5.push_back(newRound[i]);
                break;
            case 6:
                r6.push_back(newRound[i]);
                break;
            case 7:
                r7.push_back(newRound[i]);
                break;
            case 8:
                r8.push_back(newRound[i]);
                break;
            default:
                break;
        }
    }
    newRound.clear();
    
    //比較
    vector<vector<string>> rVectors3 = {r0, r1, r2, r3, r4, r5, r6, r7, r8};
    numVectors = rVectors3.size();
    for (int i = 0; i < numVectors - 1; i++) 
    {
        if (rVectors3[i].size() > 0 && rVectors3[i+1].size() > 0)
        {
            for (int j = 0; j < rVectors2[i].size(); j++) 
            {
                for (int k = 0; k < rVectors2[i+1].size(); k++) 
                {
                    string diff = "";
                    for (int l = 0; l < rVectors2[i][j].size(); l++) 
                    {
                        if (rVectors2[i][j][l] == rVectors2[i+1][k][l])
                            diff += rVectors2[i][j][l];
                        else
                        {
                            diff += "-";
                        }    
                    }
                    int count = 0;
                    for (const auto& c : diff) 
                    {
                        if (c == '-')
                            count++;
                    }
                    if (count == 3)
                    {
                        newRound.push_back(diff);
                        used.push_back(rVectors2[i][j]);
                        used.push_back(rVectors2[i+1][k]);
                    }
                    else
                    {
                        unused.push_back(rVectors2[i][j]);
                        unused.push_back(rVectors2[i+1][k]);
                    }    
                }
            }
        }
    }

    //清理
    std::sort(newRound.begin(), newRound.end());
    auto lastt2 = unique(newRound.begin(), newRound.end());
    newRound.erase(lastt2, newRound.end());
    std::sort(used.begin(), used.end());
    auto last5 = unique(used.begin(), used.end());
    used.erase(last5, used.end());
    std::sort(unused.begin(), unused.end());
    auto last6 = unique(unused.begin(), unused.end());
    unused.erase(last6, unused.end());
    std::vector<std::string> difference3;
    std::set_difference(
        unused.begin(), unused.end(),
        used.begin(), used.end(),
        std::back_inserter(difference3)
    );
    unused = difference3;

    //數unused
    for (int i = 0; i < unused.size(); i++)
    {
        int count = 0;
        for (const auto &c : unused[i])
            if (c == '1')
                count++;
        switch (count)
        {
            case 0:
                u0.push_back(unused[i]);
                break;
            case 1:
                u1.push_back(unused[i]);
                break;
            case 2:
                u2.push_back(unused[i]);
                break;
            case 3:
                u3.push_back(unused[i]);
                break;
            case 4:
                u4.push_back(unused[i]);
                break;
            case 5:
                u5.push_back(unused[i]);
                break;
            case 6:
                u6.push_back(unused[i]);
                break;
            case 7:
                u7.push_back(unused[i]);
                break;
            case 8:
                u8.push_back(unused[i]);
                break;
            default:
                break;
        }
    }
    
    //清空r
    r0.clear();
    r1.clear();
    r2.clear();
    r3.clear();
    r4.clear();
    r5.clear();
    r6.clear();
    r7.clear();
    r8.clear();
    r9.clear();
    //數used
    for (int i = 0; i < used.size(); i++)
    {
        int count = 0;
        for (const auto &c : used[i])
            if (c == '1')
                count++;
        switch (count)
        {
            case 0:
                r0.push_back(used[i]);
                break;
            case 1:
                r1.push_back(used[i]);
                break;
            case 2:
                r2.push_back(used[i]);
                break;
            case 3:
                r3.push_back(used[i]);
                break;
            case 4:
                r4.push_back(used[i]);
                break;
            case 5:
                r5.push_back(used[i]);
                break;
            case 6:
                r6.push_back(used[i]);
                break;
            case 7:
                r7.push_back(used[i]);
                break;
            case 8:
                r8.push_back(used[i]);
                break;
            default:
                break;
        }
    }

 
    if (verbose)
    {
        std::cout <<"====================="<<endl;
        std::cout <<"Column "<<++n<<endl;
        std::cout <<"====================="<<endl;
        vector<vector<string>> rVec = {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9};
        vector<vector<string>> uVec = {u0, u1, u2, u3, u4, u5, u6, u7, u8, u9};
        for(int i = 0; i < rVec.size(); i++)
        {
            for(int j = 0; j < rVec[i].size(); j++)
            {
                if (rVec[i][j] == "")
                    rVec[i].erase(rVec[i].begin() + j);
            }
        }
        for(int i = 0; i < uVec.size(); i++)
        {
            for(int j = 0; j < uVec[i].size(); j++)
            {
                if (uVec[i][j] == "")
                    uVec[i].erase(uVec[i].begin() + j);
            }
        }
        for (int i = 0; i < numVar; i++) 
        {
            if (rVec[i].size() > 0)
            {
                for (int j = 0; j < rVec[i].size(); j++)
                {
                    std::cout <<"v "<< rVec[i][j] << endl;
                }
            }
            if (uVec[i].size() > 0)
            {
                for (int j = 0; j < uVec[i].size(); j++)
                {
                    std::cout <<"  "<< uVec[i][j] << endl;
                }
            }
            if (rVec[i].size() > 0 || uVec[i].size() > 0 )
                std::cout<<"---------------------"<<endl;
        }
    }
    /*for (int i = 0; i < newRound.size(); i++)
    {
        std::cout <<"  "<< newRound[i] << endl;
    }*/

    if (verbose) 
    {
        // print the prime implicant chart of final result
    }
    
    return sol;
}

void printQmSolution(QmSolution *sol)
{
    cout << "numVar = " << sol->numVar << endl;
    cout << "primes = ";
    for (int i = 0; i < sol->primes.size(); ++i)
    {
        cout << sol->primes[i];
        if (i != sol->primes.size() - 1)
            cout << ", ";
    }
    cout << endl;
    cout << "minimumSops = ";
    for (const vector<string> &minSops : sol->minimumSops) 
    {
        for(int i = 0; i < minSops.size(); i++)
        {
            cout << minSops[i];
            if(i != minSops.size() - 1)
            {
                cout << " + ";
            }
        }
    }
    cout << endl;
}

int main()
{
    int n = 8;
    vector<int> m = {0, 2, 5, 6, 7, 8, 10, 12, 13, 14, 15};
    vector<int> d = {255};
    bool ver = false;

    clock_t start,end;
    start = clock();

    printQmSolution(solveQm(n,m,d,ver));

    end = clock();
    std::cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    return 0; 
}
