//
// Created by Dave Smith on 11/14/20.
//

#include "HTTPRequest.h"

HTTPRequest::HTTPRequest(){}
HTTPRequest::HTTPRequest(std::string url) : url(url)
{

}
json HTTPRequest::getURLJson()
{
    CURL *curl;
    CURLcode res;
    std::string readBuffer;
    json j;
    curl = curl_easy_init();
    std::string u = url;
    if(curl) {
        appendParams(u);
        curl_easy_setopt(curl, CURLOPT_URL, u.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, HTTPRequest::WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
//        std::cout << u << std:: endl;
//        std::cout << readBuffer << std::endl;
        //const char* temp = format(readBuffer);
        j = json::parse(readBuffer);

    }
    return j;
}

size_t HTTPRequest::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void HTTPRequest::removeParam(std::string param)
{
    if(params.count(param) > 0)
        params.erase(param);
}

void HTTPRequest::addParam(std::string key, std::string value)
{
    if(params.count(key) > 0)
        params[key] = value;
    else{

        std::pair<std::string, std::string> p(key, value);
        params.insert(p);
    }
}

void HTTPRequest::appendParams(std::string& url)
{
    std::map<std::string, std::string>::iterator iter = params.begin();

    for(iter; iter != params.end(); ++iter)
    {
        if(iter->first == params.begin()->first)
            url += "?" + iter->first + "=" + iter->second;
        else
            url += "&" + iter->first + "=" + iter->second;
    }

}

void HTTPRequest::connectURL(std::string url) {
    this->url = url;
}

std::string HTTPRequest::getParam(std::string param) {
    if(params.count(param) > 0)
        return params[param];
    else
        return "";
}
