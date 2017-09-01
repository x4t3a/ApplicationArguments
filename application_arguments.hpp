#ifndef X4_APPLICATION_ARGUMENTS_HEADER_GUARD
#   define X4_APPLICATION_ARGUMENTS_HEADER_GUARD

#   include <map>
#   include <string>
#   include <vector>

namespace x4::util {
    using ApplicationArgumentsMap = std::map<std::string, std::string>;

    struct SystemArguments {
        using Counter = int;
        using Char2P = char**;
        Counter const& argc;
        Char2P  const& argv;
        SystemArguments(Counter const& ac,
                        Char2P  const& av)
            : argc{ ac }, argv{ av } {}
    }; /// SystemArguments

    class ApplicationArguments : private ApplicationArgumentsMap {
        public:
            using ApplicationArgumentsMap::operator [];
            using ApplicationArgumentsMap::begin;
            using ApplicationArgumentsMap::end;

        public:
            ApplicationArguments(SystemArguments const& sys_args)
            {
                this->operator [] ("application_name") = sys_args.argv[ 0 ];
                if (sys_args.argc < 2) { return; }
                std::vector<std::string> args(sys_args.argv + 1,
                                              sys_args.argv + sys_args.argc);
                for (const auto& arg : args)
                {
                    const auto& pos = arg.find_first_of('=');
                    const auto& key = arg.substr(0, pos);
                    const auto& val = arg.substr(pos + 1);

                    if (!key.empty() && !val.empty())
                    { this->operator [] (key) = val; }
                }
            } /// ApplicationArguments
    }; /// ApplicationArguments
}; /// x4::util

#endif /// X4_APPLICATION_ARGUMENTS_HEADER_GUARD
