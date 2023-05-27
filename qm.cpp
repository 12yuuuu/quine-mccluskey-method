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
    vector<vector<string> > minimumSops;
};

/*void printTheVector(vector<pair<string,string>> r)
{
    if (r.size() > 0)
    {
        for (int i = 0; i < r.size(); i++)
        {
            std::cout << r[i].first <<" "<< r[i].second << endl;
        }
    }
}*/

QmSolution *solveQm(int numVar, vector<int> minterms, vector<int> dontcares, bool verbose)
{
    QmSolution *sol = new QmSolution;
    sol->numVar = numVar;
    vector<pair<string,string>> MIN(minterms.size());
    vector<pair<string,string>> DON(dontcares.size());
    vector<pair<string,string>> r0;
    vector<pair<string,string>> r1;
    vector<pair<string,string>> r2;
    vector<pair<string,string>> r3;
    vector<pair<string,string>> r4;
    vector<pair<string,string>> r5;
    vector<pair<string,string>> r6;
    vector<pair<string,string>> r7;
    vector<pair<string,string>> r8;
    vector<pair<string,string>> r9;
    vector<pair<string,string>> r10;
    vector<pair<string,string>> n0;
    vector<pair<string,string>> n1;
    vector<pair<string,string>> n2;
    vector<pair<string,string>> n3;
    vector<pair<string,string>> n4;
    vector<pair<string,string>> n5;
    vector<pair<string,string>> n6;
    vector<pair<string,string>> n7;
    vector<pair<string,string>> n8;
    vector<pair<string,string>> n9;
    vector<pair<string,string>> n10;
    vector<pair<string,string>> u0;
    vector<pair<string,string>> u1;
    vector<pair<string,string>> u2;
    vector<pair<string,string>> u3;
    vector<pair<string,string>> u4;
    vector<pair<string,string>> u5;
    vector<pair<string,string>> u6;
    vector<pair<string,string>> u7;
    vector<pair<string,string>> u8;
    vector<pair<string,string>> u9;
    vector<pair<string,string>> u10;
    vector<pair<string,string>> used;
    vector<pair<string,string>> unused;
    vector<pair<string,string>> newRound;
    static int n;

    //轉成二進制
    switch(numVar)
    {
    case 8:
        for (int i = 0; i < minterms.size(); i++)
        {
            bitset<8> binary(minterms[i]); 
            MIN.push_back(make_pair(binary.to_string(),to_string(minterms[i])));
        }
        for (int i = 0; i < dontcares.size(); i++)
        {
            bitset<8> binary(dontcares[i]);
            DON.push_back(make_pair(binary.to_string(),to_string(dontcares[i])));
        }
        break;
    case 9:
        for (int i = 0; i < minterms.size(); i++)
        {
            bitset<9> binary(minterms[i]); 
            MIN.push_back(make_pair(binary.to_string(),to_string(minterms[i])));   
        }
        for (int i = 0; i < dontcares.size(); i++)
        {
            bitset<9> binary(dontcares[i]);
            DON.push_back(make_pair(binary.to_string(),to_string(dontcares[i])));
        }
        break;
    case 10:
        for (int i = 0; i < minterms.size(); i++)
        {
            bitset<10> binary(minterms[i]); 
            MIN.push_back(make_pair(binary.to_string(),to_string(minterms[i])));   
        }
        for (int i = 0; i < dontcares.size(); i++)
        {
            bitset<10> binary(dontcares[i]);
            DON.push_back(make_pair(binary.to_string(),to_string(dontcares[i])));
        }
        break;
    default:
        break;
    }

    for (auto it = MIN.rbegin(); it != MIN.rend(); ++it) {
        if (it->first.size() != 10) {
            MIN.erase(std::next(it).base());
        }
    }
    for (auto it = DON.rbegin(); it != DON.rend(); ++it) {
        if (it->first.size() != 10) {
            DON.erase(std::next(it).base());
        }
    }
//================Round 1=================
    //數1的個數
    for (int i = 0; i < MIN.size(); i++)
    {
        int count = 0;
        for (const auto &c : MIN[i].first)
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
        for (const auto &c : DON[i].first)
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
    vector<vector<pair<string,string>>> rVectors = {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10};
    vector<vector<pair<string,string>>> nVectors = {n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10};
    vector<vector<pair<string,string>>> uVectors = {u0, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10};
    int numVectors = rVectors.size();
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
                    for (int l = 0; l < rVectors[i][j].first.size(); l++) 
                    {
                        if (rVectors[i][j].first[l] == rVectors[i+1][k].first[l])
                            diff += rVectors[i][j].first[l];
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
                        pair<string, string> temp = {"",""};
                        temp.first = diff;
                        temp.second = rVectors[i][j].second + "," + rVectors[i+1][k].second;
                        newRound.push_back(temp);
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
                        for (int m = 0; m < rVectors[i][k].first.size(); m++) 
                        {
                            if (rVectors[i][k].first[m] == nVectors[j][l].first[m])
                                diff += rVectors[i][k].first[m];
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
                            pair<string, string> temp = {"",""};
                            temp.first = diff;
                            temp.second = rVectors[i][j].second + "," + rVectors[i+1][k].second;
                            newRound.push_back(temp);
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
                    for (int l = 0; l < nVectors[i][j].first.size(); l++) 
                    {
                        if (nVectors[i][j].first[l] == nVectors[i+1][k].first[l])
                            diff += nVectors[i][j].first[l];
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
                        pair<string, string> temp = {"",""};
                        temp.first = diff;
                        temp.second = rVectors[i][j].second + "," + rVectors[i+1][k].second;
                        newRound.push_back(temp);
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
    std::vector<std::pair<std::string, string>> difference;
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
        for (const auto &c : unused[i].first)
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
        for (const auto &c : used[i].first)
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
        /*vector<vector<pair<string,int>>> Vectors = {r0, n0, u0, r1, n1, u1, r2, n2, u2, r3, n3, u3, r4, n4, u4, r5, n5, u5,
                                                    r6, n6, u6, r7, n7, u7, r8, n8, u8, r9, n9, u9, r10, n10, u10};*/
        vector<vector<pair<string,string>>> rVec = {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10};
        vector<vector<pair<string,string>>> nVec = {n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10};
        vector<vector<pair<string,string>>> uVec = {u0, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10};
        for (int i = 0; i < numVar+1; i++) 
        {
            if (rVec[i].size() > 0)
            {
                for (int j = 0; j < rVec[i].size(); j++)
                {
                    std::cout <<"v "<< rVec[i][j].first <<": "<< rVectors[i][j].second << endl;
                }
            }
            if (nVec[i].size() > 0)
            {
                for (int j = 0; j < nVec[i].size(); j++)
                {
                    std::cout <<"d "<< nVec[i][j].first <<": "<< nVec[i][j].second << endl;
                }
            }
            if (uVec[i].size() > 0)
            {
                for (int j = 0; j < uVec[i].size(); j++)
                {
                    std::cout <<"  "<< uVec[i][j].first <<": "<< uVec[i][j].second << endl;
                }
            }
            if (rVec[i].size() > 0 || nVec[i].size() > 0 || uVec[i].size() > 0 )
                std::cout<<"---------------------"<<endl;
        }
    }

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
        for (const auto &c : newRound[i].first)
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
    
    //比較
    vector<vector<pair<string,string>>> rVectors2 = {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9};
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
                    for (int l = 0; l < rVectors2[i][j].first.size(); l++) 
                    {
                        if (rVectors2[i][j].first[l] == rVectors2[i+1][k].first[l])
                            diff += rVectors2[i][j].first[l];
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
                        pair<string, string> temp = {"",""};
                        temp.first = diff;
                        temp.second = rVectors2[i][j].second + "," + rVectors2[i+1][k].second;
                        newRound.push_back(temp);
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
    std::sort(used.begin(), used.end());
    auto last3 = unique(used.begin(), used.end());
    used.erase(last3, used.end());
    std::sort(unused.begin(), unused.end());
    auto last4 = unique(unused.begin(), unused.end());
    unused.erase(last4, unused.end());
    std::vector<std::pair<std::string, string>> difference2;
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
        for (const auto &c : unused[i].first)
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
        for (const auto &c : used[i].first)
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
        /*vector<vector<pair<string,int>>> Vectors = {r0, n0, u0, r1, n1, u1, r2, n2, u2, r3, n3, u3, r4, n4, u4, r5, n5, u5,
                                                    r6, n6, u6, r7, n7, u7, r8, n8, u8, r9, n9, u9, r10, n10, u10};*/
        vector<vector<pair<string,string>>> rVec = {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10};
        vector<vector<pair<string,string>>> nVec = {n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10};
        vector<vector<pair<string,string>>> uVec = {u0, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10};
        for (int i = 0; i < numVar+1; i++) 
        {
            if (rVec[i].size() > 0)
            {
                for (int j = 0; j < rVec[i].size(); j++)
                {
                    std::cout <<"v "<< rVec[i][j].first <<": "<< rVectors[i][j].second << endl;
                }
            }
            if (nVec[i].size() > 0)
            {
                for (int j = 0; j < nVec[i].size(); j++)
                {
                    std::cout <<"d "<< nVec[i][j].first <<": "<< nVec[i][j].second << endl;
                }
            }
            if (uVec[i].size() > 0)
            {
                for (int j = 0; j < uVec[i].size(); j++)
                {
                    std::cout <<"  "<< uVec[i][j].first <<": "<< uVec[i][j].second << endl;
                }
            }
            if (rVec[i].size() > 0 || nVec[i].size() > 0 || uVec[i].size() > 0 )
                std::cout<<"---------------------"<<endl;
        }
    }

    

    if (verbose) 
    {
        // print the prime implicant chart of final result
    }
    
    return sol;
}

int main()
{
    int n = 10;
    vector<int> m = {0, 1, 16, 17, 128, 343, 512, 640, 1023};
    vector<int> d = {341};
    bool ver = true;

    clock_t start,end;
    start = clock();

    solveQm(n,m,d,ver);

    end = clock();
    std::cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    return 0; 
}