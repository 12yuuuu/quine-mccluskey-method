#include <string>
#include <vector>
#include <string>
#include <vector>
#include <bitset>
#include <iostream>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <cctype>
#include <time.h>

using namespace std;
// PLEASE DO NOT MODIFY THE SOLUTION STRUCT
struct QmSolution {
    int numVar;
    vector<string> primes;
    vector<vector<string> > minimumSops;
};
bool checkValidity(vector<string> &non, vector<string> &t2) 
{
    // 用於檢查所有的 non 是否都在 t2 的組合中
    for(auto &n : non) 
    {
        bool matched = false;
        for(auto &t : t2) 
        {
            bool same_digits = true;
            for (int k = 0; k < t.size(); k++) 
            {
                if (t[k] != '-' && t[k] != n[k]) 
                {
                    same_digits = false;
                    break;
                }
            }
            if (same_digits) 
            {
                matched = true;
                break;
            }
        }
        if (!matched) return false;
    }
    return true;
}

void generateCombinations(int n, int r, vector<string> &terms, vector<string> &t2, vector<vector<string>> &combinations) 
{
    string bitmask(r, 1);
    bitmask.resize(n, 0);

    do {
        vector<string> combination;
        for (int i = 0; i < n; ++i) 
        {
            if (bitmask[i]) 
            {
                combination.push_back(terms[i]);
            }
        }
        combinations.push_back(combination);
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
}

void solve(vector<string> &non, vector<string> &terms, vector<string> &t2, vector<vector<string>> &solutions) 
{
    vector<string> nonTerms; 
    vector<string> t1; 
    int firstSolutionSize = -1;

    for(auto &term : terms) 
    {
        if(find(t2.begin(), t2.end(), term) == t2.end()) 
        {
            nonTerms.push_back(term);
        } 
        else 
        {
            t1.push_back(term);
        }
    }

    for(int i = 0; i <= nonTerms.size(); ++i) {
        //cout<<i<<endl;
        if (firstSolutionSize != -1 && i > firstSolutionSize) 
        {
            break; // 如果當前的組合大小超過第一個解的大小，則停止檢查
        }
        else{
            vector<vector<string>> combinations;
            generateCombinations(nonTerms.size(), i, nonTerms, t2, combinations);
            for(auto &combination : combinations) 
            {
                vector<string> t2_candidate = t2;
                t2_candidate.insert(t2_candidate.end(), combination.begin(), combination.end());
                if(checkValidity(non, t2_candidate)) 
                {
                    solutions.push_back(t2_candidate);
                    if (firstSolutionSize == -1) 
                    {
                        firstSolutionSize = t2_candidate.size() - t2.size(); // 如果找到第一個解，則記錄其大小
                    }
                }
            }
        }
        
    }
}

// PLEASE DO NOT MODIFY THE FUNCTION DEFINITION
QmSolution *solveQm(int numVar, vector<int> minterms, vector<int> dontcares, bool verbose)
{
    QmSolution *sol = new QmSolution;
    sol->numVar = numVar;
    vector<string> MIN(minterms.size());
    vector<string> DON(dontcares.size());
    vector<string> terms;
    vector<string> nexterms;
    vector<string> nexdon;
    vector<string> nexmin;
    vector<bool> used;
    //二進制
    switch(numVar)
    {
    case 8:
        for (int i = 0; i < minterms.size(); i++)
        {
            bitset<8> binary(minterms[i]); 
            terms.push_back(binary.to_string());
            MIN.push_back(binary.to_string());
        }
        for (int i = 0; i < dontcares.size(); i++)
        {
            bitset<8> binary(dontcares[i]);
            terms.push_back(binary.to_string());
            DON.push_back(binary.to_string());
        }
        break;
    case 9:
        for (int i = 0; i < minterms.size(); i++)
        {
            bitset<9> binary(minterms[i]); 
            terms.push_back(binary.to_string());
            MIN.push_back(binary.to_string());   
        }
        for (int i = 0; i < dontcares.size(); i++)
        {
            bitset<9> binary(dontcares[i]);
            terms.push_back(binary.to_string());
            DON.push_back(binary.to_string());
        }
        break;
    case 10:
        for (int i = 0; i < minterms.size(); i++)
        {
            bitset<10> binary(minterms[i]); 
            terms.push_back(binary.to_string());
            MIN.push_back(binary.to_string());   
        }
        for (int i = 0; i < dontcares.size(); i++)
        {
            bitset<10> binary(dontcares[i]);
            terms.push_back(binary.to_string());
            DON.push_back(binary.to_string());
        }
        break;
    default:
        break;
    }

    MIN.erase(remove(MIN.begin(), MIN.end(), ""), MIN.end());
    DON.erase(remove(DON.begin(), DON.end(), ""), DON.end());
    terms.erase(remove(terms.begin(), terms.end(), ""), terms.end());
    used.resize(terms.size(), false);

    int round = 1;
    while (round <= numVar)
    {
        for (int i = 0; i < terms.size(); i++) 
        {
            for (int j = i + 1; j < terms.size(); j++) 
            {
                string diff = "";
                int countDiffOnes = 0;
                for (int k = 0; k < terms[i].size(); k++) 
                {
                    // Check if the positions of '-' in both terms are the same
                    if ((terms[i][k] == '-' && terms[j][k] != '-') || (terms[i][k] != '-' && terms[j][k] == '-')) 
                    {
                        continue;
                    }
                    else if (terms[i][k] != terms[j][k]) 
                    {
                        diff += "-";
                        if (terms[i][k] == '1' || terms[j][k] == '1')
                            countDiffOnes++;
                    } 
                    else 
                    {
                        diff += terms[i][k];
                    }
                }
                int count = 0;
                for (const auto& c : diff) 
                {
                    if (c == '-')
                        count++;
                }
                if (count == round && countDiffOnes == 1)
                {
                    nexterms.push_back(diff);
                    used[i] = true;
                    used[j] = true;
                }
            }
        }
        terms.erase(remove(terms.begin(), terms.end(), ""), terms.end());
        if (verbose)
        {
            std::cout <<"====================="<<endl;
            std::cout <<"Column "<<round<<endl;
            std::cout <<"====================="<<endl;
            for (int oneNum = 0; oneNum <= numVar; oneNum++)
            {
                bool has = false;
                for (int i = 0; i < terms.size(); i++)
                {
                    int count = 0;
                    for (const auto &c : terms[i])
                        if (c == '1')
                            count++;
                    int comCount = 0;
                    for (const auto &c : terms[i])
                        if (c == '-')
                            comCount++;
                    if (count == oneNum)
                    {
                        if (used[i])
                        {
                            if (std::find(DON.begin(), DON.end(), terms[i]) != DON.end())
                            {
                                cout << "d " << terms[i] << endl;
                                has = true;
                            }
                            else
                            {
                                cout << "v " << terms[i] << endl;
                                has = true;
                            }
                        }
                        else
                        {
                            if (round == 1)
                            {
                                cout << "  " << terms[i] << endl;
                                has = true;
                            }     
                            else if (comCount == round - 1)
                            {
                                vector<bool> repeated(terms.size(),false);
                                for (size_t j = 0; j < terms.size(); j++) 
                                {
                                    if (!repeated[j]) 
                                    {
                                        for (size_t k = j + 1; k < terms.size(); k++) 
                                        {
                                            if (terms[j] == terms[k]) 
                                            {
                                                repeated[k] = true;
                                                break;
                                            }
                                        }
                                    }
                                }
                                if (repeated[i])
                                    cout << "x " << terms[i] << endl;
                                else
                                    cout << "  " << terms[i] << endl;
                                has = true;
                            }                             
                        }
                    }    
                }
                if (has)
                    cout << "---------------------" << endl;
            }
            
        }

        if (nexterms.size() == 0)
        {
            break;
        }
        else
        {
            // Add unused terms
            for (int i = 0; i < terms.size(); i++) 
            {
                if (!used[i]) 
                {
                    // Check if the term is also present in the DON vector
                    if (std::find(DON.begin(), DON.end(), terms[i]) == DON.end())
                    {
                        nexterms.push_back(terms[i]);
                    }
                }
            }
            terms = nexterms;
            nexterms.clear();
            used.clear();
            used.resize(terms.size(), false);
        }

        for (int i = 0; i < DON.size(); i++) 
        {
            for (int j = i + 1; j < DON.size(); j++) 
            {
                string diff = "";
                int countDiffOnes = 0;
                for (int k = 0; k < DON[i].size(); k++) 
                {
                    // Check if the positions of '-' in both DON are the same
                    if ((DON[i][k] == '-' && DON[j][k] != '-') || (DON[i][k] != '-' && DON[j][k] == '-')) 
                    {
                        continue;
                    }
                    else if (DON[i][k] != DON[j][k]) 
                    {
                        diff += "-";
                        if (DON[i][k] == '1' || DON[j][k] == '1')
                            countDiffOnes++;
                    } 
                    else 
                    {
                        diff += DON[i][k];
                    }
                }
                int count = 0;
                for (const auto& c : diff) 
                {
                    if (c == '-')
                        count++;
                }
                if (count == round && countDiffOnes == 1)
                {
                    nexdon.push_back(diff);
                }
            }
        }

        DON = nexdon;
        nexdon.clear();
        round++;
    }
    for (int i = 0; i < terms.size(); i++)
    {
        for (int j = 0; j < DON.size(); j++)
        {
            bool same = true;
            for (int k = 0; k < terms[i].size(); k++)
            {
                if (terms[i][k] != DON[j][k])
                {
                    same = false;
                    break;
                }
            }
            if (same)
            {
                terms.erase(terms.begin()+i);
            }
        }
    }
    std::sort(terms.begin(), terms.end());
    auto last = unique(terms.begin(), terms.end());
    terms.erase(last, terms.end());
    vector<string> pri;

    for (int i = 0; i < terms.size(); i++)
    {
        string output = "";
        for (int j = 0; j < terms[i].size(); j++)
        {
            if (terms[i][j] == '0')
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
            else if (terms[i][j] == '1')
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
    
    vector<vector<string>> sop;
    vector<string> t1;
    for (int i = 0; i < MIN.size(); i++) 
    {
        int matchIdx = -1; // Use this to record the match index
        int count = 0;
        for (int j = 0; j < terms.size(); j++) 
        {
            bool same_digits = true;
            for (int k = 0; k < terms[j].size(); k++) 
            {
                if (terms[j][k] != '-' && terms[j][k] != MIN[i][k]) 
                {
                    same_digits = false;
                    break;
                }
            }
            if (same_digits) 
            {
                count++;
                matchIdx = j;
            }
        }
        if (count == 1)
        {
            t1.push_back(terms[matchIdx]);
        }
    }

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
    
    vector<vector<string>> solutions;
    vector<string> t2(t1); 
    solve(non, terms, t2, solutions);

    for (int i = 0; i < solutions.size(); i++)
    {
        std::sort(solutions[i].begin(), solutions[i].end());
        auto last = unique(solutions[i].begin(), solutions[i].end());
        solutions[i].erase(last, solutions[i].end());   
    }

    for (int h = 0; h < solutions.size(); h++)
    {
        vector<string> s;
        for (int i = 0; i < solutions[h].size(); i++)
        {
            string output = "";
            for (int j = 0; j < solutions[h][i].size(); j++)
            {
                if (solutions[h][i][j] == '0')
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
                else if (solutions[h][i][j] == '1')
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
            s.push_back(output);
        }
        sop.push_back(s);
    }
    
    if (verbose)
    {
        int width = 4;
        cout << "=====================" << endl
            << "Prime Implicant Chart" << endl
            << "=====================" << endl;
        cout << std::setw(width * 5.3) << "|";
        for (int i = 0; i < minterms.size(); i++)
            cout << std::setw(width) << minterms[i] << "|";
        cout << endl;
        cout << "--------------------+";
        for (int i = 0; i < minterms.size(); i++)
            cout << "----+";
        cout << endl;
        std::sort(MIN.begin(), MIN.end());
        auto lastt = unique(MIN.begin(), MIN.end());
        MIN.erase(lastt, MIN.end());
        for (int i = 0; i < solutions.size(); i++)
        {
            for (int j = 0; j < solutions[i].size(); j++)
            {
                vector<char> cha(MIN.size(), ' ');
                for (int m = 0; m < sop[i][j].size(); m++)
                {
                    if (m % 2 == 1 && sop[i][j][m] != '\'')
                    {
                        sop[i][j].insert(m, " ");
                    }
                }
                cout << std::setw(width * 5) << std::left << sop[i][j] << "|";
                for (int k = 0; k < MIN.size(); k++)
                {
                    bool same_digits = true;
                    for (int m = 0; m < solutions[i][j].size(); m++)
                    {
                        if (solutions[i][j][m] != '-' && solutions[i][j][m] != MIN[k][m])
                        {
                            same_digits = false;
                            break;
                        }
                    }
                    if (same_digits)
                    {
                        cha[k] = 'x';
                    }   
                }
                for (int l = 0; l < cha.size(); l++)
                    cout << std::setw(width) << cha[l] << "|";
                cout << endl;
            }
            cout << "--------------------+";
            for (int i = 0; i < minterms.size(); i++)
                cout << "----+";
            cout << endl;
        }
    }
    
    sol->primes = pri;
    sol->minimumSops = sop;
    
    return sol;
};

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
    for (int i = 0; i < sol->minimumSops.size(); i++) 
    {
        for(int j = 0; j < sol->minimumSops[i].size(); j++)
        {
            cout << sol->minimumSops[i][j];
            if(j != sol->minimumSops[i].size() - 1)
            {
                cout << " + ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int n = 10;
    vector<int> m = {0, 1, 16, 17, 128, 343, 512, 640, 1023};
    vector<int> d = {341};
    //vector<int> m = {39, 47, 111, 217, 257, 414, 435, 477, 490, 589, 703, 728, 880, 1019};
    //vector<int> d = {2, 40, 120, 196, 202, 220, 245, 294, 303, 309, 328, 341, 354, 375, 
    //         439, 516, 558, 581, 627, 649, 651, 659, 708, 801, 852, 869, 915, 934, 962};
    //vector<int> m = {24, 37, 83, 138, 217, 228, 269, 354, 368, 376, 415, 476, 508};
    //vector<int> d = {54, 175, 214, 301, 316, 332, 336, 358, 398, 412, 428, 473};
    bool ver = true;

    clock_t start,end;
    start = clock();

    printQmSolution(solveQm(n,m,d,ver));

    end = clock();
    std::cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    return 0; 
}