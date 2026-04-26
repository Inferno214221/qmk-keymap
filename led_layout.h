#define LED_LAYOUT_moonlander( \
    k0A, k0B, k0C, k0D, k0E, k0F, k0G,            k6A, k6B, k6C, k6D, k6E, k6F, k6G, \
    k1A, k1B, k1C, k1D, k1E, k1F, k1G,            k7A, k7B, k7C, k7D, k7E, k7F, k7G, \
    k2A, k2B, k2C, k2D, k2E, k2F, k2G,            k8A, k8B, k8C, k8D, k8E, k8F, k8G, \
    k3A, k3B, k3C, k3D, k3E, k3F,                      k9B, k9C, k9D, k9E, k9F, k9G, \
    k4A, k4B, k4C, k4D, k4E,      k5D,            kBD,      kAC, kAD, kAE, kAF, kAG, \
                             k5A, k5B, k5C,  kBE, kBF, kBG \
) { \
    k0A, k1A, k2A, k3A, k4A, \
    k0B, k1B, k2B, k3B, k4B, \
    k0C, k1C, k2C, k3C, k4C, \
    k0D, k1D, k2D, k3D, k4D, \
    k0E, k1E, k2E, k3E, k4E, \
    k0F, k1F, k2F, k3F, \
    k0G, k1G, k2G, \
    k5A, k5B, k5C, k5D, \
\
    k6G, k7G, k8G, k9G, kAG, \
    k6F, k7F, k8F, k9F, kAF, \
    k6E, k7E, k8E, k9E, kAE, \
    k6D, k7D, k8D, k9D, kAD, \
    k6C, k7C, k8C, k9C, kAC, \
    k6B, k7B, k8B, k9B, \
    k6A, k7A, k8A, \
    kBG, kBF, kBE, kBD, \
}

#define RGB_LAYOUT_moonlander( \
    k0A, k0B, k0C, k0D, k0E, k0F, k0G,            k6A, k6B, k6C, k6D, k6E, k6F, k6G, \
    k1A, k1B, k1C, k1D, k1E, k1F, k1G,            k7A, k7B, k7C, k7D, k7E, k7F, k7G, \
    k2A, k2B, k2C, k2D, k2E, k2F, k2G,            k8A, k8B, k8C, k8D, k8E, k8F, k8G, \
    k3A, k3B, k3C, k3D, k3E, k3F,                      k9B, k9C, k9D, k9E, k9F, k9G, \
    k4A, k4B, k4C, k4D, k4E,      k5D,            kBD,      kAC, kAD, kAE, kAF, kAG, \
                             k5A, k5B, k5C,  kBE, kBF, kBG, \
    XXX \
) { \
    { k0A, k0B, k0C, k0D, k0E, k0F, k0G }, \
    { k1A, k1B, k1C, k1D, k1E, k1F, k1G }, \
    { k2A, k2B, k2C, k2D, k2E, k2F, k2G }, \
    { k3A, k3B, k3C, k3D, k3E, k3F, XXX }, \
    { k4A, k4B, k4C, k4D, k4E, XXX, XXX }, \
    { k5A, k5B, k5C, k5D, XXX, XXX, XXX }, \
\
    { k6A, k6B, k6C, k6D, k6E, k6F, k6G }, \
    { k7A, k7B, k7C, k7D, k7E, k7F, k7G }, \
    { k8A, k8B, k8C, k8D, k8E, k8F, k8G }, \
    { XXX, k9B, k9C, k9D, k9E, k9F, k9G }, \
    { XXX, XXX, kAC, kAD, kAE, kAF, kAG }, \
    { XXX, XXX, XXX, kBG, kBF, kBE, kBD }, \
}
