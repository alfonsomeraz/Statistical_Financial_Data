//
// Created by Dave Smith on 11/14/20.
//

#ifndef HTTPREQUEST_HTTPREQUEST_H
#define HTTPREQUEST_HTTPREQUEST_H

#include <string>
#include <curl/curl.h>
#include "JSON.h"
#include <iostream>
#include <map>
#include <cstring>
#include <utility>
using json = nlohmann::json;

class HTTPRequest {

public:
    HTTPRequest();
    HTTPRequest(std::string url);
    void connectURL(std::string url);
    json getURLJson();
    void addParam(std::string key, std::string value);
    std::string getParam(std::string param);
    void removeParam(std::string param);
private:
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
    std::map<std::string, std::string> params;
    void appendParams(std::string& url);
    std::string url;

};
#endif //HTTPREQUEST_HTTPREQUEST_H
