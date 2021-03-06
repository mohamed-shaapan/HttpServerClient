//
// Created by abdelrhman on 11/3/18.
//

#ifndef HTTPSERVERCLIENT_REQUEST_H
#define HTTPSERVERCLIENT_REQUEST_H

#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <IOHandler.h>
#include "HttpMessage.h"

using namespace std ;


class Request: public HttpMessage {

 public:
  Request();
  Request(HTTP_METHODS method, const string &file_name, const string &host_name, int port,
          const string &body = "");
  virtual ~Request();
  void setFileName(const string &file_name);
  void setHostName(const string &host_name);
  void setPort(int port);
  const string &getFileName() const;
  const string &getHostName() const;
  int getPort() const;


    string getBody(){
      return HttpMessage::getBody();
    }

    void setMethod(HTTP_METHODS method){
         HttpMessage::setMethod(method);
     }
     HTTP_METHODS getMethod() const{
         return HttpMessage::getMethod();
     }
    void setKeyVal(string key, string val) {
        HttpMessage::setKeyVal(key,val);
    }
    void setBody(string body){
        HttpMessage::setBody(body);
    }
    string getKey_val(string key){
        return HttpMessage::getKey_val(key);
    }

    string toString();


 private:
    string fileName , hostName;
    int port ;



};

#endif //HTTPSERVERCLIENT_REQUEST_H
