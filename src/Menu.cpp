#include "Menu.h"

Menu::Menu()
{
    elements.bIsShown = bShowMenu;
    elements.Menu = std::bind(&Menu::Draw, this);
    elements.Shroud = std::bind(&Menu::SHROUD, this);
    elements.Hud = std::bind(&Menu::HUD, this);
}

void Menu::Draw()
{
    if (bShowMenu)
        MainMenu();

    if (bShowDemoWindow && bShowMenu)
        ImGui::ShowDemoWindow();

    if (bShowStyleEditor && bShowMenu)
        ImGui::ShowStyleEditor();
}

void Menu::MainMenu()
{
    static ImVec2 MenuSize = ImVec2(800, 600);
    static ImVec2 ScreenSize = g_dxWindow->GetScreenSize();
    ImVec2 start = { ScreenSize.x / 2 - MenuSize.x / 2, ScreenSize.y / 2 - MenuSize.y / 2 };
    ImGui::SetNextWindowPos(start);
    ImGui::SetNextWindowSize(MenuSize);
    if (!ImGui::Begin("(DX11) ImGui External Base", &bShowMenu, 96))
    {
        ImGui::End();
        return;
    }            
    
    ImGui::Text("BASE MENU (PREVIEW)");
    ImGui::Text("BUILD VERSION: v1.0.0");
    ImGui::Text("BUILD DATE: 8/11/2024");
    ImGui::Checkbox("IMGUI DEMO WINDOW", &this->bShowDemoWindow);
    ImGui::Checkbox("STYLE EDITOR", &this->bShowStyleEditor);
    if (ImGui::Button("EXIT", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetTextLineHeightWithSpacing())))
        this->bRunning = false;

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    ImGui::BeginChild("GameInfo", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetTextLineHeightWithSpacing() * 8), ImGuiChildFlags_Border);
    {
        ImGui::Text("pGame: 0x%llX" , BF4::GetGame());
        auto pClient = BF4::GetLocalClient();
        ImGui::Text("pClient: 0x%llX", pClient);
        if (pClient)
        {
            ImGui::Text("TeamID: %d", BF4::GetClientTeamID(pClient));
            ImGui::Text("Name: %s", BF4::GetClientName(pClient).c_str());

            std::vector<__int64> outClients;
            BF4::GetClientArray(&outClients);
            ImGui::Text("Clients: %d", outClients.size());

            __int64 pSoldier = BF4::GetClientSoldier(pClient);
            if (pSoldier)
            {
                BF4::Vector3 pos = BF4::GetSoldierPos(pSoldier);
                ImGui::Text("HEALTH: %.0f", BF4::GetHealthPercent(pSoldier));
                ImGui::Text("POS: { %.0f, %.0f, %.0f }", pos.x, pos.y, pos.z);
            }
        }
    }
    ImGui::EndChild();

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    ImGui::BeginChild("Features", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetTextLineHeightWithSpacing() * 3), ImGuiChildFlags_Border);
    {
        static ImVec2 szTooltip = ImGui::CalcTextSize("?");
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.260f, 0.590f, 0.980f, 0.400f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.260f, 0.590f, 0.980f, 0.400f));
        
        //  ESP
        ImGui::Button("?");
        if (ImGui::IsItemHovered())
            ImGui::SetTooltip("Render snaplines to entities as well as entity bones.");
        ImGui::SameLine();
        ImGui::Checkbox("ESP", &g_Menu->bESP);

        ImGui::PopStyleColor(2);
    }
    ImGui::EndChild();

    ImGui::End();
}

void Menu::SHROUD()
{
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(g_dxWindow->GetScreenSize());
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4());
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.f);
    if (!ImGui::Begin("##SHROUDWINDOW", (bool*)true, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoInputs)) 
    {
        ImGui::PopStyleColor();
        ImGui::PopStyleVar();
        ImGui::End();
        return;
    }
    ImGui::PopStyleColor();
    ImGui::PopStyleVar();
    ImGui::End();
}

void Menu::HUD()
{
    ImVec2 draw_pos = g_dxWindow->GetCloneWindowPos();
    ImVec2 draw_size = g_dxWindow->GetCloneWindowSize();
    ImGui::SetNextWindowPos(draw_pos);
    ImGui::SetNextWindowSize(draw_size);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.00f, 0.00f, 0.00f, 0.00f));
    ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(IM_COL32_RED));
    if (!ImGui::Begin("##HUDWINDOW", (bool*)true, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoInputs))
    {
        ImGui::PopStyleColor();
        ImGui::PopStyleVar();
        ImGui::End();
        return;
    }
    ImGui::PopStyleColor(2);
    ImGui::PopStyleVar();


    ImDrawList* ImDraw = ImGui::GetWindowDrawList();
    auto center = ImVec2({ draw_size.x * .5f, draw_size.y * .5f });
    auto top_center = ImVec2({ draw_size.x * .5f, draw_size.y * 0.0f });
    GUI::DrawTextCentered(top_center + draw_pos, IM_COL32_RED, "https://github.com/NightFyre/DX11-ImGui-External-Base", 12.f);

    if (g_Menu->bESP)
        g_Menu->ESP();

    ImGui::End();
}

DxWindow::SOverlay Menu::GetOverlay() { return elements; }

void Menu::UpdateOverlayViewState(bool bState) { elements.bIsShown = bState; }

void BF4Menu::ESP()
{
    ImVec2 WindowPos = g_dxWindow->GetCloneWindowPos();
    ImVec2 WindowSize = g_dxWindow->GetCloneWindowSize();
    ImVec2 AbsoluteCenter = { ((WindowSize.x / 2) + WindowPos.x), ((WindowSize.y / 2) + WindowPos.y) };
    ImDrawList* pDraw = ImGui::GetWindowDrawList();
    
    __int64 pLocalClient = BF4::GetLocalClient();
    if (!pLocalClient)
        return;

    __int64 pLocalSoldier = BF4::GetClientSoldier(pLocalClient);
    if (!pLocalSoldier)
        return;

    __int32 localTeam = BF4::GetClientTeamID(pLocalClient);

    std::vector<__int64> clients;
    if (!BF4::GetClientArray(&clients))
        return;

    __int32 index = -1;
    for (auto client : clients)
    {
        index++;

        if (client == pLocalClient)
            continue;

        __int64 clientSoldier = BF4::GetClientSoldier(client);
        if (!Memory::IsValidPtr(clientSoldier))
            continue;

        float health = BF4::GetHealthPercent(clientSoldier);
        if (health < 0.0f)
            continue;

        __int32 teamID = BF4::GetClientTeamID(client);
        BF4::Vector3 pos = BF4::GetSoldierPos(clientSoldier);
        if (pos.IsValid())
            continue;
        
        BF4::Vector2 screen;
        if (!BF4::WorldToScreen(pos, &screen))
            continue;


        const char* name;
        ImColor col(IM_COL32_WHITE);
        bool isVis = BF4::IsVisible(clientSoldier);
        bool isFriendly = BF4::IsFriendly(client, localTeam);
        float distancem = BF4::GetSoldierPos(pLocalSoldier).Distance(pos);
        switch (isFriendly)
        {
            case true: 
                col = isVis ? IM_COL32_GREEN : IM_COL32_BLUE; 
                name = "ALLY";
                break;
            case false: col = isVis ? IM_COL32_YELLOW : IM_COL32_RED;  
                name = "ENEMY";
                break;
            default: name = "";
        }

        if (isFriendly)
            continue;

        //  Render Entity
        pDraw->AddLine(AbsoluteCenter, { screen.x + WindowPos.x, screen.y + WindowPos.y }, col, 1.0f);
        GUI::DrawTextCenteredf({ screen.x + WindowPos.x, screen.y + WindowPos.y }, col, "%s - %.1fm", 14.f, name, distancem);

        if (distancem > 100.f)
            continue;

        //  Render Bones
        for (auto& limb : BF4::BoneVector)
        {
            BF4::Vector3 prevBone, currBone;
            for (auto i = 0; i < limb.size(); i++)
            {
                __int32 index = limb.at(i);
                BF4::GetBoneByIndex(clientSoldier, index, &currBone);

                BF4::Vector2 boneScreenA;
                if (!BF4::WorldToScreen(currBone, &boneScreenA))
                    continue;

                ImVec2 screenTransA = { boneScreenA.x + WindowPos.x, boneScreenA.y + WindowPos.y };
                if (prevBone.IsValid())
                {
                    prevBone = currBone;
                    continue;
                }

                BF4::Vector2 boneScreenB;
                if (!BF4::WorldToScreen(prevBone, &boneScreenB))
                    continue;

                ImVec2 screenTransB = { boneScreenB.x + WindowPos.x, boneScreenB.y + WindowPos.y };

                prevBone = currBone;

                //  Render Bone
                pDraw->AddLine(screenTransA, screenTransB, col, 1.0f);
            }
        }
    }


}

void GUI::TextCentered(const char* pText)
{
    float windowWidth = ImGui::GetWindowSize().x;
    float textWidth = ImGui::CalcTextSize(pText).x;
    float posX = (windowWidth - textWidth) * 0.5f;
    ImGui::SetCursorPosX(posX);
    ImGui::Text(std::string(pText).c_str());
}

//  @ATTN: max buffer is 256chars
void GUI::TextCenteredf(const char* pText, ...)
{
    va_list args;
    va_start(args, pText);
    char buffer[256];
    vsnprintf(buffer, sizeof(buffer), pText, args);
    va_end(args);

    TextCentered(buffer);
}

void GUI::DrawText_(ImVec2 pos, ImColor color, const char* pText, float fontSize)
{
    ImGui::GetWindowDrawList()->AddText(ImGui::GetFont(), fontSize, pos, color, pText, pText + strlen(pText), 800, 0);
}

//  @ATTN: max buffer is 256chars
void GUI::DrawTextf(ImVec2 pos, ImColor color, const char* pText, float fontSize, ...)
{
    va_list args;
    va_start(args, fontSize);
    char buffer[256];
    vsnprintf(buffer, sizeof(buffer), pText, args);
    va_end(args);

    DrawText_(pos, color, buffer, fontSize);
}

void GUI::DrawTextCentered(ImVec2 pos, ImColor color, const char* pText, float fontSize)
{
    float textSize = ImGui::CalcTextSize(pText).x;
    ImVec2 textPosition = ImVec2(pos.x - (textSize * 0.5f), pos.y);
    DrawText_(textPosition, color, pText, fontSize);
}

//  @ATTN: max buffer is 256chars
void GUI::DrawTextCenteredf(ImVec2 pos, ImColor color, const char* pText, float fontSize, ...)
{
    va_list args;
    va_start(args, fontSize);
    char buffer[256];
    vsnprintf(buffer, sizeof(buffer), pText, args);
    va_end(args);

    DrawTextCentered(pos, color, buffer, fontSize);
}