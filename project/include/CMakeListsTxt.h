#include "Configuration.h"
#include "Project.h"
#include "globaloptions.h"

#include <fw/filesystem.hpp>
#include <ostream>

struct CMakeProjectExporter
{
    explicit CMakeProjectExporter(const Project &project);
    std::string LookupLibraryName(const Component &comp);
    void createCMakeListsFiles(const GlobalOptions &opts);
private:
    void dumpDoNotModifyWarning(std::ostream &os);
    void extractSystemComponents(const Component &comp, std::unordered_set<std::string> &visited, std::vector<const Component *> &results) const;
    std::vector<const Component *> extractSystemComponents() const;
    void dumpTargetIncludes(std::ostream &os, const std::string &target, const std::string &access, const std::unordered_set<std::string> &includes);
    void dumpTargetLibraries(std::ostream &os, const std::string &target, const std::string &access, const std::unordered_set<Component *> components);
    static constexpr const char *cmakeSystemProjectPrefix = "evoke_system_lib_";
    static constexpr const char *cmakelists_txt = "CMakeLists.txt";
    const Project &project_;
};

