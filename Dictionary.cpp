
// Created by yurim on 6/12/2022.
//
#include "HashMap.hpp"
#ifndef _DICTIONARY_HPP_
#define _DICTIONARY_HPP_
class InvalidKey:public std::invalid_argument
{
 public:
  InvalidKey():std::invalid_argument("")
  {}
  InvalidKey(const std::string &a):std::invalid_argument(a)
  {}
};
 class Dictionary: public HashMap<std::string ,std::string>
{
 private:
 public :
  Dictionary()= default;
  Dictionary(std::vector<std::string> first, std::vector<std::string> second)
  {
   if(first.size()!=second.size())
   {
     throw std::out_of_range ("Error size");
   }
    for (unsigned  i = 0; i < first.size(); ++i)
    {
      this->insert (first[i],second[i]);
    }

  }
  bool erase(std::string key) override
  {
      bool check = HashMap<std::string, std::string>::erase(key);
      if(!check)
      {
        throw InvalidKey("error");
      }
      return true;
  }
   template<class Itertaor>
  void update(Itertaor a
              ,Itertaor b)
  {
    for (auto i = a; i !=b; ++i)
    {
      std::hash<std::string> hash_func;
      int check = hash_func (i->first) & (capacity1-1);
      bool check2 =this->contains_key (i->first);
      if(check2)
      {

        for (unsigned  j = 0; j < this->table[check].size(); ++j)
        {
          if( this->table[check][j].first==i->first)
          {
            this->table[check][j].second=i->second;
          }
        }

      }
      else
      {
        table[check].push_back ({i->first,i->second});
        M++;
      }
    }

  }
};

#endif //_DICTIONARY_HPP_
