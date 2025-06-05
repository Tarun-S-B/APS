#include <iostream>
#include <string>
#include <vector>
#include <unordered_map> 
#include <mutex>         
#include <utility>      

using namespace std;

struct FlowData {
    double rtt;                 
    double loss_rate;           
    int window_size;
    double position_exposure;   

    FlowData(double r = 0.0, double lr = 0.0, int ws = 0, double pe = 0.0)
        : rtt(r), loss_rate(lr), window_size(ws), position_exposure(pe) {}

    void print() const {
        cout << "  RTT: " << rtt << "ms, Loss Rate: " << loss_rate
             << "%, Window Size: " << window_size;
        if (position_exposure != 0.0) { 
            cout << ", Position Exposure: " << position_exposure;
        }
        cout << endl;
    }
};

struct InstrumentDetails {
    // Static Data
    string name;
    string sector;
    string currency;
    string issuer;

    double latest_price;
    string analytics_summary;        
    vector<string> risk_factors; 

    InstrumentDetails(string n = "", string s = "", string curr = "", string iss = "",
                      double lp = 0.0, string an_sum = "", vector<string> rf = {})
        : name(move(n)), sector(move(s)), currency(move(curr)), issuer(move(iss)),
          latest_price(lp), analytics_summary(move(an_sum)), risk_factors(move(rf)) {}

    void print() const {
        cout << "  Name: " << name << ", Sector: " << sector
             << ", Currency: " << currency << ", Issuer: " << issuer << endl;
        cout << "  Latest Price: " << latest_price
             << ", Analytics: \"" << analytics_summary << "\"" << endl;
        cout << "  Risk Factors: ";
        if (risk_factors.empty()) {
            cout << "None listed";
        } else {
            for (size_t i = 0; i < risk_factors.size(); ++i) {
                cout << risk_factors[i] << (i == risk_factors.size() - 1 ? "" : "; ");
            }
        }
        cout << endl;
    }
};

int main() {
    cout << "## Managing Network Traffic / Trading Sessions ##\n" << endl;
    unordered_map<string, FlowData> flow_monitor;

    string network_flow_key = "192.168.1.10:54321-10.0.0.5:443"; // Example: SRC_IP:PORT-DST_IP:PORT
    string trading_flow_key = "AssetID_EURUSD_Trade001";     // Example: Asset ID or Trade ID

    flow_monitor[network_flow_key] = FlowData(12.5, 0.05, 131072); // RTT, Loss, Window Size
    cout << "Added Network Flow: " << network_flow_key << endl;
    flow_monitor[network_flow_key].print();

    flow_monitor[trading_flow_key] = FlowData(0, 0, 0, 150000.75); // No RTT/Loss/Window, but has position exposure
    cout << "\nAdded Trading Flow: " << trading_flow_key << endl;
    flow_monitor[trading_flow_key].print();

    cout << "\nUpdating RTT for Network Flow: " << network_flow_key << endl;
    if (flow_monitor.count(network_flow_key)) {
        flow_monitor[network_flow_key].rtt = 10.2;
        flow_monitor[network_flow_key].loss_rate = 0.02;
        cout << "Updated Data:" << endl;
        flow_monitor[network_flow_key].print();
    }

    cout << "\nRapid Lookup for Trading Flow: " << trading_flow_key << endl;
    auto it_trade = flow_monitor.find(trading_flow_key);
    if (it_trade != flow_monitor.end()) {
        cout << "Found. Details:" << endl;
        it_trade->second.print();
    } else {
        cout << "Trading Flow " << trading_flow_key << " not found." << endl;
    }


    cout << "## Managing Financial Instruments (Aladdin Style) ##\n" << endl;
    unordered_map<string, InstrumentDetails> aladdin_instrument_db;

    string cusip_msft = "594918104"; // Microsoft Corp.
    string isin_goog = "US02079K3059"; // Alphabet Inc. Class A
    string internal_id_tesla = "ALADDIN_TSLA001";

    aladdin_instrument_db[cusip_msft] = InstrumentDetails(
        "Microsoft Corp.", "Technology", "USD", "Microsoft Corporation",
        450.95, "Strong Buy", {"Cloud Growth", "AI Integration"}
    );
    cout << "Added Instrument (CUSIP): " << cusip_msft << endl;
    aladdin_instrument_db[cusip_msft].print();

    aladdin_instrument_db[isin_goog] = InstrumentDetails(
        "Alphabet Inc. Class A", "Technology", "USD", "Alphabet Inc.",
        180.50, "Buy", {"Ad Revenue", "Search Dominance", "Regulatory Scrutiny"}
    );
    cout << "\nAdded Instrument (ISIN): " << isin_goog << endl;
    aladdin_instrument_db[isin_goog].print();

    aladdin_instrument_db[internal_id_tesla] = InstrumentDetails(
        "Tesla, Inc.", "Automotive", "USD", "Tesla, Inc.",
        185.60, "Hold", {"EV Market Competition", "Production Scalability", "Elon Musk Key Person Risk"}
    );
    cout << "\nAdded Instrument (Internal ID): " << internal_id_tesla << endl;
    aladdin_instrument_db[internal_id_tesla].print();


    cout << "\nUpdating Price and Analytics for CUSIP: " << cusip_msft << endl;
    if (aladdin_instrument_db.count(cusip_msft)) {
        aladdin_instrument_db[cusip_msft].latest_price = 452.10;
        aladdin_instrument_db[cusip_msft].analytics_summary = "Continued Strong Buy";
        aladdin_instrument_db[cusip_msft].risk_factors.push_back("Increased Market Competition");
        cout << "Updated Data:" << endl;
        aladdin_instrument_db[cusip_msft].print();
    }

    cout << "\nRapid Lookup for Instrument (Internal ID): " << internal_id_tesla << endl;
    auto it_instrument = aladdin_instrument_db.find(internal_id_tesla);
    if (it_instrument != aladdin_instrument_db.end()) {
        cout << "Found. Details:" << endl;
        it_instrument->second.print();
    } else {
        cout << "Instrument with ID " << internal_id_tesla << " not found." << endl;
    }

    

    return 0;
}