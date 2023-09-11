#include <iostream>
#include <string>

int main()
{
    std::string expression;
    std::string st;
    std::string exit;
    std::cout << "Entering expression: ";
    getline(std::cin, expression);

    int sz;
    for(const auto& ch: expression)
    {
        if((ch == '*') || (ch == '/'))
        {std::cout << "expected " << ch << "\n";
            sz = st.size();
            if(sz > 0)
            {
                for(; sz >= 0; sz--)
                {
                    if(st[sz] == '(')
                        break;
                    if((st[sz] == '*') || (st[sz] == '/'))
                    {
                        exit.push_back(st[sz]);
                        st.erase(sz);
                    }
                    else break;
                }
            }
            st.push_back(ch);
        }
        else if((ch == '-') || (ch == '+'))
            {std::cout << "expected " << ch << "\n";
                sz = st.size();

                if(sz > 0)
                {
                    for(; sz >= 0; sz--)
                    {
                        if(st[sz] == '(')
                            break;

                        exit.push_back(st[sz]);
                        st.erase(sz);
                    }
                }
                st.push_back(ch);
            }
            else if(ch == '(')
                {
                    st.push_back(ch);
                }
                else if(ch == ')')
                    {
                        if(sz > 0)
                        {
                            for(; sz >= 0; sz--)
                            {
                                if(st[sz] == '(')
                                {
                                    st.erase(sz);
                                    break;
                                }

                                exit.push_back(st[sz]);
                                st.erase(sz);
                            }
                        }
                    }
                    else if(ch == ' ')
                        {
                        }
                        else{
                            exit.push_back(ch);
                        }
    }

    sz = st.size();
    if(sz > 0)
    {
        for(; sz >= 0; sz--)
        {
            exit.push_back(st[sz]);
            st.erase(sz);
        }
    }
    /*for(const auto& ch: expression)
    {
        switch(ch)
        {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '0': exit.push_back(ch); break;
            case '(': st.push_back(ch); break;
            case ')':{
                for(const auto& sym: st)
                {
                    if(sym == '(')
                    {
                        st.pop_back(); break;
                    }
                    exit.push_back(st.back());
                    st.pop_back();
                }
            break;}

            case '+':
            case '-':{//std::cout << "expected " << ch << "st = " << st;
                if(st.size()>0)
                {
                    int i = st.size() - 1;
                    while((i >= 0) && (st[i] != '('))
                    {//std::cout << "\n\nst.rend() = " << *it << "\n\n";
                        exit.push_back(st[i]);
                        st.pop_back();
                        i--;
                    }
                }
                st.push_back(ch);
                //std::cout << "new st = " << st << " new exit = " << exit << "\n";
            break;}

            case '*':
            case '/':{//std::cout << "expected " << ch << "st = " << st;
                if(st.size()>0)
                {
                    int i = st.size() - 1;
                    while((i >= 0) && ((st[i] == '*') || (st[i] == '/')))
                    {
                        exit.push_back(st[i]);
                        st.pop_back();
                        i--;
                    }
                }
                st.push_back(ch);
                //std::cout << "new st = " << st << " new exit = " << exit << "\n";
            break;}
        }
    }

    std::cout << "st = " <<st;
    if(st.size()>0)
    {
        int i = st.size() - 1;
        while(i >= 0)
        {
            exit.push_back(st[i]);
            st.pop_back();
            i--;
        }
    }*/

    std::cout << "Exit: " << exit;
    return 0;
}
