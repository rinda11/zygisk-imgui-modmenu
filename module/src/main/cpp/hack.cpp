#include <cstdint>
#include <cstring>
#include <cstdio>
#include <unistd.h>
#include <dlfcn.h>
#include <string>
#include <EGL/egl.h>
#include <GLES3/gl3.h>

#include "hack.h"
#include "log.h"
#include "game.h"
#include "utils.h"
#include "xdl.h"
#include "imgui.h"
#include "imgui_impl_android.h"
#include "imgui_impl_opengl3.h"
#include "MemoryPatch.h"
#include <Fonts/FontAwesome6_regular.h>
#include <Fonts/GoogleSans.h>

#include <Fonts/IconsFontAwesome6.h>

#include <Fonts/FontAwesome6_solid.h>
static int                  g_GlHeight, g_GlWidth;
static bool                 g_IsSetup = false;
static std::string          g_IniFileName = "";
static utils::module_info   g_TargetModule{};

void *getAbsAddress(uintptr_t offset) {
    uintptr_t base = reinterpret_cast<uintptr_t>(g_TargetModule.start_address);
    return reinterpret_cast<void*>(base + offset);
}


//here

static float playerspeedd = 0.0f;

static bool onehitt = false;
static bool fastloott = false;
static bool fasttravell = false;
static bool dumbenemy = false;
static bool attackspedd = false;
static bool maxduraaa = false;
static bool freecraft = false;
static bool shopInboxx = false;
static bool instantbuild = false;
static bool freesplitt = false;
static bool unliifood = false;
static bool levelskilll = false;
static bool allskiin = false;
static bool bikeskinn = false;
static bool weaponmfy = false;
static bool globalmap = false;


float (*old_PlayerSpeed)(void *instance);
float PlayerSpeed(void *instance) {
    if (instance != NULL && playerspeedd) {
        return (float) playerspeedd;
    }
    return old_PlayerSpeed(instance);
}

int (*old_OneHitt)(void *instance);
int OneHitt(void *instance) {
    if (instance != NULL) {
        if (onehitt) {
            return 9999;
        }
    }
    return old_OneHitt(instance);
}

void (*old_FasstLoot)(void *instance);
void FasstLoot(void *instance) {
    if (instance != NULL) {
        if (fastloott) {
            return;
        }
    }
    return old_FasstLoot(instance);
}

float (*old_FasttTravel)(void *instance);
float FasttTravel(void *instance) {
    if (instance != NULL) {
        if (fasttravell) {
            return 1.0f;
        }
    }
    return old_FasttTravel(instance);
}

bool (*old_DumpEnemy)(void *instance);
bool DumpEnemy(void *instance) {
    if (instance != NULL) {
        if (dumbenemy) {
            return true;
        }
    }
    return old_DumpEnemy(instance);
}

float (*old_AttackSpeed)(void *instance);
float AttackSpeed(void *instance) {
    if (instance != NULL) {
        if (attackspedd) {
            return 100.0f;
        }
    }
    return old_AttackSpeed(instance);
}

int (*old_MaxDurability)(void *instance);
int MaxDurability(void *instance) {
    if (instance != NULL) {
        if (maxduraaa) {
            return 9999;
        }
    }
    return old_MaxDurability(instance);
}

bool (*old_FreeCraftt)(void *instance);
bool FreeCraftt(void *instance) {
    if (instance != NULL) {
        if (freecraft) {
            return true;
        }
    }
    return old_FreeCraftt(instance);
}

bool (*old_FreeCraftt2)(void *instance);
bool FreeCraftt2(void *instance) {
    if (instance != NULL) {
        if (freecraft) {
            return true;
        }
    }
    return old_FreeCraftt2(instance);
}

bool (*old_FreeCraftt3)(void *instance);
bool FreeCraftt3(void *instance) {
    if (instance != NULL) {
        if (freecraft) {
            return true;
        }
    }
    return old_FreeCraftt3(instance);
}

bool (*old_FreeCraftt4)(void *instance);
bool FreeCraftt4(void *instance) {
    if (instance != NULL) {
        if (freecraft) {
            return true;
        }
    }
    return old_FreeCraftt4(instance);
}

int (*old_FreeCraftt5)(void *instance);
int FreeCraftt5(void *instance) {
    if (instance != NULL) {
        if (freecraft) {
            return 1;
        }
    }
    return old_FreeCraftt5(instance);
}

int (*old_InboxItemm)(void *instance);
int InboxItemm(void *instance) {
    if (instance != NULL) {
        if (shopInboxx) {
            return 9999;
        }
    }
    return old_InboxItemm(instance);
}

bool (*old_InstantBuildd)(void *instance);
bool InstantBuildd(void *instance) {
    if (instance != NULL) {
        if (instantbuild) {
            return true;
        }
    }
    return old_InstantBuildd(instance);
}

bool (*old_FreeSplitt)(void *instance);
bool FreeSplitt(void *instance) {
    if (instance != NULL) {
        if (freesplitt) {
            return true;
        }
    }
    return old_FreeSplitt(instance);
}

void (*old_UnlimitedFood)(void *instance);
void UnlimitedFood(void *instance) {
    if (instance != NULL) {
        if (unliifood) {
            return;
        }
    }
    return old_UnlimitedFood(instance);
}

bool (*old_NoSkill)(void *instance);
bool NoSkill(void *instance) {
    if (instance != NULL) {
        if (levelskilll) {
            return true;
        }
    }
    return old_NoSkill(instance);
}

bool (*old_UnlockAllSkin)(void *instance);
bool UnlockAllSkin(void *instance) {
    if (instance != NULL) {
        if (allskiin) {
            return true;
        }
    }
    return old_UnlockAllSkin(instance);
}

bool (*old_UnlockBikeSkinn)(void *instance);
bool UnlockBikeSkinn(void *instance) {
    if (instance != NULL) {
        if (bikeskinn) {
            return false;
        }
    }
    return old_UnlockBikeSkinn(instance);
}

bool (*old_UnlockBikeSkinn2)(void *instance);
bool UnlockBikeSkinn2(void *instance) {
    if (instance != NULL) {
        if (bikeskinn) {
            return false;
        }
    }
    return old_UnlockBikeSkinn2(instance);
}

bool (*old_UnlockWeapon)(void *instance);
bool UnlockWeapon(void *instance) {
    if (instance != NULL) {
        if (weaponmfy) {
            return true;
        }
    }
    return old_UnlockWeapon(instance);
}

bool (*old_UnlockGlobalMap)(void *instance);
bool UnlockGlobalMap(void *instance) {
    if (instance != NULL) {
        if (globalmap) {
            return true;
        }
    }
    return old_UnlockGlobalMap(instance);
}






#include "input.h"
#define HOOK(t,r,o) utils::hook(getAbsAddress(t),(func_t)r,(func_t*)&o)
HOOKAF(void, Input, void *thiz, void *ex_ab, void *ex_ac) {
    origInput(thiz, ex_ab, ex_ac);
    ImGui_ImplAndroid_HandleInputEvent((AInputEvent *)thiz);
    return;}
void SetupImGui() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();

    io.IniFilename = g_IniFileName.c_str();
    io.DisplaySize = ImVec2((float)g_GlWidth, (float)g_GlHeight);

    ImGui_ImplAndroid_Init(nullptr);
    ImGui_ImplOpenGL3_Init("#version 300 es");
    //ImGui::StyleColorsDark();
    RindaStyleCustom();
	io.Fonts->Clear();
    float fontBaseSize = 28.4f;

    static const ImWchar rangesBasic[] = {
        0x0020,0x00FF, // Basic Latin + Latin Supplement
        0x03BC,0x03BC, // micro
        0x03C3,0x03C3, // small sigma
        0x2013,0x2013, // en dash
        0x2264,0x2264, // less-than or equal to
        0,
    };
    ImFontConfig font_cfg;
    io.Fonts->AddFontFromMemoryCompressedTTF(GoogleSans_compressed_data, GoogleSans_compressed_size, fontBaseSize, &font_cfg, rangesBasic);


    float iconFontSize = fontBaseSize * 2.0f / 3.0f; // FontAwesome fonts need to have their sizes reduced by 2.0f/3.0f in order to align correctly
    static const ImWchar icons_ranges[] = {
        ICON_MIN_FA,ICON_MAX_16_FA,
        0
    };
    ImFontConfig icons_config;
    icons_config.MergeMode = true;
    icons_config.PixelSnapH = true;
    icons_config.GlyphMinAdvanceX = iconFontSize;
    io.Fonts->AddFontFromMemoryCompressedTTF(fa_solid_compressed_data, fa_solid_compressed_size, iconFontSize, &icons_config, icons_ranges);

    

    ImGui::GetStyle().ScaleAllSizes(3.0f);
}

EGLBoolean (*old_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
EGLBoolean hook_eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    eglQuerySurface(dpy, surface, EGL_WIDTH, &g_GlWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &g_GlHeight);

    if (!g_IsSetup) {
      SetupImGui();
      g_IsSetup = true;
    }

    ImGuiIO &io = ImGui::GetIO();

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame(g_GlWidth, g_GlHeight);
    ImGui::NewFrame();
    ImGui::SetNextWindowSize(ImVec2(700, 500), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSizeConstraints(ImVec2(400, 300), ImVec2(1000, 800));
    if (ImGui::Begin(OBFUSCATE("Last Day on Earth v1.29.2 [64] | RindaModz"), nullptr)) {
    float menuWidth = ImGui::GetWindowWidth();
    float menuHeight = ImGui::GetWindowHeight();

    // Shadow settings (sesuaikan ukuran dinamis)
    RectangleShadowSettings shadowSettings;
    shadowSettings.rectSize = ImVec2(menuWidth - 5, menuHeight - 5);
    shadowSettings.sigma = 10;
    shadowSettings.padding = ImVec2(3.f, 3.f);
    shadowSettings.rectPos = shadowSettings.padding;
    shadowSettings.rings = 4;
    shadowSettings.spacingBetweenRings = 3;
    shadowSettings.samplesPerCornerSide = 3;
    shadowSettings.spacingBetweenSamples = 15;
    shadowSettings.shadowColor = ImVec4(colorshadow);
    drawRectangleShadowVerticesAdaptive(shadowSettings);

    // Kolom untuk tab
    ImGui::Columns(2, nullptr, true); // Aktifkan resize kolom
    ImGui::SetColumnOffset(1, 150); // Offset kolom kedua

    static int tab = 1;
    if (ImGui::Button(OBFUSCATE("Player"), ImVec2(-1, 60))) tab = 1;
    if (ImGui::Button(OBFUSCATE("Resour"), ImVec2(-1, 60))) tab = 2;
    if (ImGui::Button(OBFUSCATE("Unlock"), ImVec2(-1, 60))) tab = 3;
    if (ImGui::Button(OBFUSCATE("Camera"), ImVec2(-1, 60))) tab = 4;
    if (ImGui::Button(OBFUSCATE("Info"), ImVec2(-1, 60))) tab = 5;

    ImGui::NextColumn();

    // Konten tab disesuaikan
    if (tab == 1) {
        ImGui::Text(OBFUSCATE("Player Menu"));
        ImGui::Separator();
        ImGui::Checkbox(OBFUSCATE("One Hit"), &onehitt);
        ImGui::Checkbox(OBFUSCATE("Fast Loot"), &fastloott);
        ImGui::Checkbox(OBFUSCATE("Fast Travel"), &fasttravell);
        ImGui::Checkbox(OBFUSCATE("Dumb Enemy"), &dumbenemy);
        ImGui::Separator();
        ImGui::SliderFloat(OBFUSCATE("Player Speed"), &playerspeedd, 0.0f, 15.0f, OBFUSCATE("%.3f"));
        ImGui::Separator();
        ImGui::Checkbox(OBFUSCATE("Attack Speed"), &attackspedd);
        ImGui::Checkbox(OBFUSCATE("Max Durability"), &maxduraaa);
        ImGui::Separator();
    } else if (tab == 2) {
        ImGui::Text(OBFUSCATE("Resource Menu"));
        ImGui::Separator();
        ImGui::Checkbox(OBFUSCATE("Free Craft"), &freecraft);
        ImGui::Checkbox(OBFUSCATE("Inbox +999"), &shopInboxx);
        ImGui::Checkbox(OBFUSCATE("Instant Build (Fiew Item)"), &instantbuild);
        ImGui::Checkbox(OBFUSCATE("Free split (split to get more)"), &freesplitt);
        ImGui::Checkbox(OBFUSCATE("Unlimited Item & Food & Water"), &unliifood);
        ImGui::Separator();
        ImGui::Checkbox(OBFUSCATE("No Level Skill Requirement"), &levelskilll);
        ImGui::Separator();
    } else if (tab == 3) {
        ImGui::Text(OBFUSCATE("Unlock Menu"));
        ImGui::Separator();
        ImGui::Checkbox(OBFUSCATE("Unlock All Skin"), &allskiin);
        ImGui::Checkbox(OBFUSCATE("Unlock Bike Skin"), &bikeskinn);
        ImGui::Checkbox(OBFUSCATE("Unlock Weapon Modify"), &weaponmfy);
        ImGui::Checkbox(OBFUSCATE("unlock Global map(event)"), &globalmap);
        ImGui::Separator();
    } else if (tab == 4) {
        ImGui::Text(OBFUSCATE("Camera Menu (Beta)"));
        ImGui::Separator();
        //ImGui::SliderFloat(OBFUSCATE("Weapon View"), &weaponview, 0.0f, 15.0f, OBFUSCATE("value = %.3f"));
        ImGui::Separator();
    } else if (tab == 5) {
        ImGui::Text(OBFUSCATE("Architecture : %s"), aarch);  
        ImGui::Text(OBFUSCATE("FrameRate %.3f ms (%.1f FPS)"), 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::Separator();
         
        ImGui::Text(OBFUSCATE("Modded by : Rinda"));
        
        ImGui::Text(OBFUSCATE("Telegram  : t.me/RindaMods"));
        ImGui::Text(OBFUSCATE("Discord   : rinda_escobar"));
        ImGui::Separator();
        
        ImGui::Text(OBFUSCATE("Join Telegram Channel for More Update : https://t.me/RindaModz"));
        ImGui::Separator();
     }
    ImGui::End(); 
   }
    
  }
    ImGui::EndFrame();
    ImGui::Render();
    glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    return old_eglSwapBuffers(dpy, surface);
}

void hack_start(const char *_game_data_dir) {
    LOGI("hack start | %s", _game_data_dir);
    do {
        sleep(1);
        g_TargetModule = utils::find_module(TargetLibName);
    } while (g_TargetModule.size <= 0);
    LOGI("%s: %p - %p",TargetLibName, g_TargetModule.start_address, g_TargetModule.end_address);

    // TODO: hooking/patching here

HOOK_LIB("libil2cpp.so", "0x383B5E0", PlayerSpeed, old_PlayerSpeed);
HOOK_LIB("libil2cpp.so", "0x3E2A750", UnlockGlobalMap, old_UnlockGlobalMap);
HOOK_LIB("libil2cpp.so", "0x37E565C", UnlockWeapon, old_UnlockWeapon);
HOOK_LIB("libil2cpp.so", "0x2E25F04", UnlockBikeSkinn2, old_UnlockBikeSkinn2);
HOOK_LIB("libil2cpp.so", "0x2E29B9C", UnlockBikeSkinn, old_UnlockBikeSkinn);
HOOK_LIB("libil2cpp.so", "0x3843058", UnlockAllSkin, old_UnlockAllSkin);
HOOK_LIB("libil2cpp.so", "0x35B7500", NoSkill, old_NoSkill);
HOOK_LIB("libil2cpp.so", "0x37F0AA8", UnlimitedFood, old_UnlimitedFood);
HOOK_LIB("libil2cpp.so", "0x37C849C", FreeSplitt, old_FreeSplitt);
HOOK_LIB("libil2cpp.so", "0x38A8A9C", InstantBuildd, old_InstantBuildd);
HOOK_LIB("libil2cpp.so", "0x35608B4", InboxItemm, old_InboxItemm);
HOOK_LIB("libil2cpp.so", "0x3603FD0", FreeCraftt5, old_FreeCraftt5);
HOOK_LIB("libil2cpp.so", "0x360286C", FreeCraftt4, old_FreeCraftt4);
HOOK_LIB("libil2cpp.so", "0x37C5120", FreeCraftt3, old_FreeCraftt3);
HOOK_LIB("libil2cpp.so", "0x35FEA64", FreeCraftt2, old_FreeCraftt2);
HOOK_LIB("libil2cpp.so", "0x36223B0", FreeCraftt, old_FreeCraftt);
HOOK_LIB("libil2cpp.so", "0x4B63160", MaxDurability, old_MaxDurability);
HOOK_LIB("libil2cpp.so", "0x4A6BA3C", AttackSpeed, old_AttackSpeed);
HOOK_LIB("libil2cpp.so", "0x39329AC", DumpEnemy, old_DumpEnemy);
HOOK_LIB("libil2cpp.so", "0x3809200", FasttTravel, old_FasttTravel);
HOOK_LIB("libil2cpp.so", "0x36F1C84", FasstLoot, old_FasstLoot);
HOOK_LIB("libil2cpp.so", "0x4A6D2C4", OneHitt, old_OneHitt);





    
}

static void RindaStyleCustom()
{
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;

    // Set colors
colors[ImGuiCol_Text]                   = ImVec4(0.88f, 0.88f, 0.88f, 1.00f); // Teks utama - sedikit lebih terang
colors[ImGuiCol_TextDisabled]           = ImVec4(0.50f, 0.50f, 0.50f, 1.00f); // Teks yang dinonaktifkan - redup
colors[ImGuiCol_WindowBg]               = ImVec4(0.12f, 0.12f, 0.12f, 0.94f); // Latar belakang jendela - abu-abu gelap
colors[ImGuiCol_ChildBg]                = ImVec4(0.14f, 0.14f, 0.14f, 0.58f); // Child window - abu-abu medium
colors[ImGuiCol_PopupBg]                = ImVec4(0.10f, 0.10f, 0.10f, 0.92f); // Popup - abu-abu gelap pekat
colors[ImGuiCol_Border]                 = ImVec4(0.20f, 0.20f, 0.20f, 0.50f); // Garis border - abu-abu medium
colors[ImGuiCol_BorderShadow]           = ImVec4(0.00f, 0.00f, 0.00f, 0.00f); // Bayangan border - tidak terlihat
colors[ImGuiCol_FrameBg]                = ImVec4(0.18f, 0.20f, 0.22f, 1.00f); // Background frame - abu-abu modern
colors[ImGuiCol_FrameBgHovered]         = ImVec4(0.30f, 0.30f, 0.30f, 0.60f); // Frame hover - abu-abu terang
colors[ImGuiCol_FrameBgActive]          = ImVec4(0.30f, 0.35f, 0.40f, 0.75f); // Frame aktif - abu-abu medium dengan sedikit biru
colors[ImGuiCol_TitleBg]                = ImVec4(0.08f, 0.08f, 0.08f, 1.00f); // Header judul - sangat gelap
colors[ImGuiCol_TitleBgActive]          = ImVec4(0.14f, 0.14f, 0.14f, 1.00f); // Header aktif - abu-abu gelap
colors[ImGuiCol_TitleBgCollapsed]       = ImVec4(0.05f, 0.05f, 0.05f, 0.80f); // Header collapsed - lebih gelap
colors[ImGuiCol_MenuBarBg]              = ImVec4(0.10f, 0.10f, 0.10f, 1.00f); // MenuBar - abu-abu gelap
colors[ImGuiCol_ScrollbarBg]            = ImVec4(0.08f, 0.08f, 0.08f, 0.50f); // Latar belakang scrollbar
colors[ImGuiCol_ScrollbarGrab]          = ImVec4(0.24f, 0.24f, 0.24f, 1.00f); // Scrollbar - abu-abu terang
colors[ImGuiCol_ScrollbarGrabHovered]   = ImVec4(0.32f, 0.32f, 0.32f, 1.00f); // Scrollbar hover - abu-abu terang
colors[ImGuiCol_ScrollbarGrabActive]    = ImVec4(0.40f, 0.40f, 0.40f, 1.00f); // Scrollbar aktif
colors[ImGuiCol_CheckMark]              = ImVec4(0.26f, 0.55f, 0.75f, 1.00f); // Tanda centang - biru redup
colors[ImGuiCol_SliderGrab]             = ImVec4(0.24f, 0.48f, 0.70f, 1.00f); // Slider - biru lembut
colors[ImGuiCol_SliderGrabActive]       = ImVec4(0.30f, 0.56f, 0.76f, 1.00f); // Slider aktif
colors[ImGuiCol_Button]                 = ImVec4(0.18f, 0.35f, 0.45f, 0.60f); // Tombol default - abu-abu biru redup
colors[ImGuiCol_ButtonHovered]          = ImVec4(0.20f, 0.40f, 0.50f, 0.80f); // Tombol hover - lebih terang
colors[ImGuiCol_ButtonActive]           = ImVec4(0.15f, 0.30f, 0.40f, 1.00f); // Tombol aktif - lebih gelap
colors[ImGuiCol_Header]                 = ImVec4(0.22f, 0.48f, 0.68f, 0.40f); // Header - biru transparan
colors[ImGuiCol_HeaderHovered]          = ImVec4(0.24f, 0.50f, 0.70f, 0.80f); // Header hover - biru lembut
colors[ImGuiCol_HeaderActive]           = ImVec4(0.24f, 0.50f, 0.70f, 1.00f); // Header aktif
colors[ImGuiCol_Separator]              = ImVec4(0.28f, 0.28f, 0.28f, 0.50f); // Separator - abu-abu terang
colors[ImGuiCol_SeparatorHovered]       = ImVec4(0.32f, 0.60f, 0.80f, 0.78f); // Separator hover - biru lembut
colors[ImGuiCol_SeparatorActive]        = ImVec4(0.34f, 0.64f, 0.84f, 1.00f); // Separator aktif
colors[ImGuiCol_ResizeGrip]             = ImVec4(0.22f, 0.48f, 0.68f, 0.25f); // Resize grip - biru redup transparan
colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.24f, 0.50f, 0.70f, 0.67f); // Resize grip hover
colors[ImGuiCol_ResizeGripActive]       = ImVec4(0.24f, 0.50f, 0.70f, 0.95f); // Resize grip aktif
colors[ImGuiCol_Tab]                    = ImVec4(0.15f, 0.15f, 0.15f, 0.86f); // Tab - abu-abu gelap
colors[ImGuiCol_TabHovered]             = ImVec4(0.22f, 0.48f, 0.68f, 0.80f); // Tab hover - biru transparan
colors[ImGuiCol_TabActive]              = ImVec4(0.18f, 0.18f, 0.18f, 1.00f); // Tab aktif - abu-abu gelap
colors[ImGuiCol_TabUnfocused]           = ImVec4(0.10f, 0.10f, 0.10f, 0.97f); // Tab tidak fokus
colors[ImGuiCol_TabUnfocusedActive]     = ImVec4(0.14f, 0.14f, 0.14f, 1.00f); // Tab tidak fokus tapi aktif
colors[ImGuiCol_PlotLines]              = ImVec4(0.70f, 0.70f, 0.70f, 1.00f); // Garis plot - abu-abu terang
colors[ImGuiCol_PlotLinesHovered]       = ImVec4(0.80f, 0.80f, 0.80f, 1.00f); // Plot hover
colors[ImGuiCol_PlotHistogram]          = ImVec4(0.88f, 0.68f, 0.10f, 1.00f); // Histogram - oranye kekuningan
colors[ImGuiCol_PlotHistogramHovered]   = ImVec4(0.95f, 0.60f, 0.10f, 1.00f); // Histogram hover
colors[ImGuiCol_TextSelectedBg]         = ImVec4(0.24f, 0.50f, 0.70f, 0.35f); // Background teks yang dipilih
colors[ImGuiCol_DragDropTarget]         = ImVec4(0.30f, 0.60f, 0.90f, 1.00f); // Target drag-drop
colors[ImGuiCol_NavHighlight]           = ImVec4(0.30f, 0.60f, 0.90f, 1.00f); // Highlight navigasi
colors[ImGuiCol_NavWindowingHighlight]  = ImVec4(1.00f, 1.00f, 1.00f, 0.70f); // Highlight windowing
colors[ImGuiCol_NavWindowingDimBg]      = ImVec4(0.80f, 0.80f, 0.80f, 0.20f); // Background windowing
colors[ImGuiCol_ModalWindowDimBg]       = ImVec4(0.10f, 0.10f, 0.10f, 0.60f); // Background modal window


    // Set rounding and padding
    style.GrabRounding = 6.0f;
    style.FrameRounding = 6.0f;    // Rounded corners for frames
    style.ChildRounding = 6.0f;   // Rounded corners for child windows
    style.WindowRounding = 8.0f;  // Rounded corners for windows
    style.PopupRounding = 8.0f;   // Rounded corners for popups
    style.ScrollbarRounding = 6.0f; // Rounded corners for scrollbars
    style.TabRounding = 6.0f;     // Rounded corners for tabs
    style.FramePadding = ImVec2(8, 4); // Padding within frames
    style.ItemSpacing = ImVec2(8, 8);  // Spacing between items
    style.WindowPadding = ImVec2(10, 10); // Padding inside the window

    // Set Size 
    style.ScrollbarSize = 25.0f;
    
    }

void hack_prepare(const char *_game_data_dir) {
    LOGI("hack thread: %d", gettid());
    int api_level = utils::get_android_api_level();
    LOGI("api level: %d", api_level);
    g_IniFileName = std::string(_game_data_dir) + "/files/imgui.ini";
    sleep(5);

    void *sym_input = DobbySymbolResolver("/system/lib/libinput.so", "_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageE");
    if (NULL != sym_input){
        DobbyHook((void *)sym_input, (dobby_dummy_func_t) myInput, (dobby_dummy_func_t*)&origInput);
    }
    
    void *egl_handle = xdl_open("libEGL.so", 0);
    void *eglSwapBuffers = xdl_sym(egl_handle, "eglSwapBuffers", nullptr);
    if (NULL != eglSwapBuffers) {
        utils::hook((void*)eglSwapBuffers, (func_t)hook_eglSwapBuffers, (func_t*)&old_eglSwapBuffers);
    }
    xdl_close(egl_handle);

    hack_start(_game_data_dir);
}
