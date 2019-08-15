#include <vector>
#include <iostream>

#include "boost/program_options.hpp"

#include "SANAResult.hpp"
#include "SANAConfiguration.hpp"
#include "Graph.hpp"
#include "Utility.hpp"

namespace {
    const size_t ERROR_IN_COMMAND_LINE = 1;
    const size_t SUCCESS = 0;
    const size_t ERROR_UNHANDLED_EXCEPTION = 2;
    void print_usage(boost::program_options::options_description desc,
            std::ostream& out) {
        out << "Usage: sana_exe --networks network1 network2 [additional_networks...]" << std::endl;
        out << desc << std::endl;
    }
}


int main(int argc, char **argv) {
    try {
        namespace po = boost::program_options;

        po::options_description desc("Allowed SANA options");
        po::variables_map vm;
        desc.add_options()
            ("help", "Produce help message")
            ("networks", po::value<std::vector<std::string>>()->multitoken()->required()
             "List of networks: must be of type LEDA");
        try {
            po::store(po::parse_command_line(argc, argv, desc), vm);
            po::notify(vm);
        } catch (po::error &e) {
            std::cerr << "Commandline parser error: " << e.what() << std::endl;
            print_usage(desc, std::cerr);
            return ERROR_IN_COMMAND_LINE;
        }
        std::vector<std::string> network_list = vm["networks"].as<std::vector<std::string>>();
        if (network_list.size() < 2) {
            std::cerr << "Minimum required number of networks is two. Received one: ";
            std::cerr << network_list.at(0) << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << "Unknown exception: " << e.what() << std::endl;
        return ERROR_UNHANDLED_EXCEPTION;
    } catch (...) {
        std::cerr << "Exception of unknown type!" << std::endl;
    }

    // std::vector <Graph> networkList;
    // for (int i = 1; i < argc; i++) {
        // networkList.push_back(Utility::LoadBinaryGraphFromLEDAFile(argv[i]));
        // networkList.push_back(Utility::LoadBinaryGraphFromEdgeList(argv[i]));
    // }

    // SANAConfiguration sanaConfig;
    // SANA sana(sanaConfig);
    // SANAResult results = sana.StartAligner(networkList);
    return SUCCESS;
}

