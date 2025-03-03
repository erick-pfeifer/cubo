load("@rules_platform//platform_data:defs.bzl", "platform_data")

def atsame54n20a_binary(name = "", binary = ""):
    return platform_data(name = name, target = binary, platform = "//targets/atsame54n20a:atsame54n20a")