#include <eosio/eosio.hpp>
using namespace eosio;

CONTRACT farmmonkey : public contract {
   public:
      using contract::contract;

      farmmonkey(name receiver, name code,  datastream<const char*> ds): contract(receiver, code, ds), _users(receiver, receiver.value) {}

      ACTION login( name user );

   private:
      TABLE user_struct {
         name username;
         std::string first_name;
         std::string last_name;
         std::string street;
         std::string city;
         std::string state;

         auto primary_key() const { return username.value; } 
      };

      typedef multi_index<name("users"), user_struct> users_table;
      
      users_table _users;
};

EOSIO_DISPATCH(farmmonkey, (login))