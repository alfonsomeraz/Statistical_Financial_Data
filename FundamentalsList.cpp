//
// Created by Alfonso Meraz on 12/9/20.
//

#include "FundamentalsList.h"

FundamentalsList::FundamentalsList() : Stock("AAPL"){
    setText();
}

void FundamentalsList::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(assetType);
    window.draw(symbol);
    window.draw(description);
    window.draw(lastPrice);
    window.draw(openPrice);
    window.draw(highPrice);
    window.draw(lowPrice);
    window.draw(closePrice);
    window.draw(netChange);
    window.draw(totalVolume);
    window.draw(volatility);
    window.draw(weekHigh52);
    window.draw(weekLow52);
    window.draw(pERatio);
    window.draw(divAmount);
    window.draw(divYield);
}

void FundamentalsList::setPositions() {
    assetType.setPosition(20,20);
    symbol.setPosition(20,60);
    description.setPosition(20,100);

    lastPrice.setPosition(20,180);
    openPrice.setPosition(20,220);
    highPrice.setPosition(20,260);
    lowPrice.setPosition(20,300);
    closePrice.setPosition(20,340);

    netChange.setPosition(450,180);
    totalVolume.setPosition(450,220);
    volatility.setPosition(450,260);
    weekHigh52.setPosition(450,300);

    weekLow52.setPosition(950,180);
    pERatio.setPosition(950,220);
    divAmount.setPosition(950,260);
    divYield.setPosition(950,300);
}

void FundamentalsList::setText() {
    setFonts();
    setColors();
    setStrings();
    setPositions();
}

void FundamentalsList::setFonts() {
    if(!font.loadFromFile("OpenSans-Bold.ttf"))
    {
        std::cout << "Font did not load.\n";
        exit(1);
    }
    assetType.setFont(font);
    symbol.setFont(font);
    description.setFont(font);
    lastPrice.setFont(font);
    openPrice.setFont(font);
    highPrice.setFont(font);
    lowPrice.setFont(font);
    closePrice.setFont(font);
    netChange.setFont(font);
    totalVolume.setFont(font);
    volatility.setFont(font);
    weekHigh52.setFont(font);
    weekLow52.setFont(font);
    pERatio.setFont(font);
    divAmount.setFont(font);
    divYield.setFont(font);
}

void FundamentalsList::setStrings() {
    ////// Can I do this? //////////

    assetType.setString("Asset Type: " + getAssetType());
    symbol.setString("Symbol: " + getSymbol());
    description.setString("Description: " + getDescription());
    lastPrice.setString("Last Price: " + getLastPrice());
    openPrice.setString("Open Price: " + getOpenPrice());
    highPrice.setString("High Price: " + getHighPrice());
    lowPrice.setString("Low Price: " + getLowPrice());
    closePrice.setString("Close Price: " + getClosePrice());
    netChange.setString("Net Change: " + getNetChange());
    totalVolume.setString("Total Volume: " + getTotalVolume());
    volatility.setString("Volatility: " + getVolatility());
    weekHigh52.setString("52 Week High: " + get52WkHigh());
    weekLow52.setString("52 Week Low: " + get52WkLow());
    pERatio.setString("PE Ratio: " + getPEratio());
    divAmount.setString("Dividend Amount: " + getDivAmount());
    divYield.setString("Dividend Yield: " + getDivYield());
}

void FundamentalsList::setColors() {
    assetType.setFillColor(sf::Color::White);
    symbol.setFillColor(sf::Color::White);
    description.setFillColor(sf::Color::White);
    lastPrice.setFillColor(sf::Color::White);
    openPrice.setFillColor(sf::Color::White);
    highPrice.setFillColor(sf::Color::White);
    lowPrice.setFillColor(sf::Color::White);
    closePrice.setFillColor(sf::Color::White);
    netChange.setFillColor(sf::Color::White);
    totalVolume.setFillColor(sf::Color::White);
    volatility.setFillColor(sf::Color::White);
    weekHigh52.setFillColor(sf::Color::White);
    weekLow52.setFillColor(sf::Color::White);
    pERatio.setFillColor(sf::Color::White);
    divAmount.setFillColor(sf::Color::White);
    divYield.setFillColor(sf::Color::White);
}
