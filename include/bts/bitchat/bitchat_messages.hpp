#pragma once
#include <bts/bitchat/bitchat_private_message.hpp>

namespace bts { namespace bitchat {

  // other protocol messages... not encapsulated by data_message
  struct inv_message 
  {
      static const message_type type = message_type::inv_msg;
      std::vector<fc::uint128>  items;
  };

  // other protocol messages... not encapsulated by data_message
  struct cache_inv_message 
  {
      static const message_type type = message_type::cache_inv_msg;
      std::vector<fc::uint128>  items;
  };

  struct get_priv_message
  {
      static const message_type type = message_type::get_priv_msg;
      get_priv_message(){}
      get_priv_message( const fc::uint128& p )
      {
        items.push_back(p);
      }
      std::vector<fc::uint128>  items;
  };
  struct get_cache_priv_message
  {
      static const message_type type = message_type::get_cache_priv_msg;
      get_cache_priv_message(){}
      get_cache_priv_message( const fc::uint128& p )
      {
        items.push_back(p);
      }
      get_cache_priv_message( const std::vector<fc::uint128>& i )
      :items(i)
      {}

      std::vector<fc::uint128>  items;
  };

  /**
   *  Used to request all inventory after the given time.
   */
  struct get_inv_message
  {
      static const message_type type = message_type::get_inv_msg;
      fc::time_point_sec after;
  };

  /**
   *  
   */
  struct get_cache_inv_message
  {
      static const message_type type = message_type::get_cache_inv_msg;
      get_cache_inv_message( const fc::time_point& s, const fc::time_point e )
      :start_time(s),end_time(e){}
      get_cache_inv_message(){}
      fc::time_point_sec start_time;
      fc::time_point_sec end_time;
  };

} } // bts::bitchat

FC_REFLECT( bts::bitchat::inv_message,      (items) )
FC_REFLECT( bts::bitchat::get_priv_message, (items) )
FC_REFLECT( bts::bitchat::get_inv_message,  (after) )

FC_REFLECT( bts::bitchat::cache_inv_message,      (items) )
FC_REFLECT( bts::bitchat::get_cache_priv_message, (items) )
FC_REFLECT( bts::bitchat::get_cache_inv_message,  (start_time)(end_time) )
