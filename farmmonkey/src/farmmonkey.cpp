#include <farmmonkey.hpp>

ACTION farmmonkey::login( name user ) {
   require_auth(user);
   
   auto user_iterator = _users.find(user.value);
   
   if(user_iterator == _users.end()){
     // create a new record for the user (_users)
     user_iterator = _users.emplace(user, [&](auto& new_user){
       new_user.username = user;
     });
   }
}
