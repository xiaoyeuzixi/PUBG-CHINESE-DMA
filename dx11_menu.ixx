export module dx11_menu;
import std;

export class dx11_menu {
public:
	static inline struct esp {
		static inline bool player = true;
		static inline bool player_bone = true;
		static inline bool player_bone_id = false; // 新增骨骼ID开关
		static inline int player_bone_style = 0; // 0: 无头骨, 1: 有头骨
		static inline bool player_box = true;
		static inline bool player_name = true;
		static inline bool player_weapon = true;
		static inline bool player_dis = true;
		static inline bool player_team = true;
		static inline bool player_health = true;
		static inline int player_health_style = 0; // 0: 渐变红黄绿, 1: 跟随血量渐变(整条颜色变化), 2: 科技风格子
		static inline bool player_energy = true;
		static inline bool player_kills = true;
		static inline bool player_action = true;
		static inline bool player_groggy = true;
		static inline bool player_line = true;
		static inline bool player_ignore_me = true;
		static inline bool player_ignore_team = true;
		static inline bool player_permission = true;
		static inline bool player_warning = true;
		static inline bool player_aim_warning = true; // 被瞄警告开关
		static inline bool player_vis_check = true;
		static inline bool player_out_of_fov_arrow = true; // 视场外箭头开关
		static inline float player_out_of_fov_arrow_radius = 200.0f; // 箭头半径
		static inline float player_out_of_fov_arrow_size = 15.0f; // 箭头大小
		static inline float color_player_out_of_fov_arrow[4] = { 1.0f, 0.0f, 0.0f, 1.0f }; // 箭头颜色
		static inline bool vehicle = true;
		static inline bool vehicle_hp = true;
		static inline bool vehicle_fuel = true;
		static inline bool vehicle_tire = true;
		static inline bool vehicle_dis = true;

		// 物资设置
		static inline bool item_collapse = true;
		static inline bool item_airdrop = true;
		static inline bool item_grenade = true;
		static inline bool item_meds = true;
		static inline float item_size = 14.0f;
		static inline char item_search_buf[64] = "";
		static inline int item_filter_type = 0; // 0:全部, 1:武器, 2:配件, 3:装备, 4:药品, 5:弹药, 6:空投/盒子, 7:其他
		static inline std::map<std::string, bool> item_filter_map;

		// 载具详细设置
		static inline bool vehicle_name = true;
		static inline int vehicle_tire_style = 0; // 0:文字, 1:图形
		static inline float color_vehicle_name[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
		static inline float color_vehicle_hp[4] = { 0.0f, 1.0f, 0.0f, 1.0f };
		static inline float color_vehicle_fuel[4] = { 1.0f, 0.5f, 0.0f, 1.0f };
		static inline float color_vehicle_tire[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
		static inline float size_vehicle_name = 14.0f;
		static inline float size_vehicle_hp = 14.0f;
		static inline float size_vehicle_fuel = 14.0f;
		static inline float size_vehicle_tire = 14.0f;
		static inline char vehicle_search_buf[64] = "";
		static inline int vehicle_filter_type = 0; // 0:全部, 1:汽车, 2:摩托, 3:船, 4:其他
		static inline std::map<std::string, bool> vehicle_filter_map;


		// 颜色设置
		static inline float color_box[4] = { 0.0f, 0.0f, 1.0f, 1.0f };
		static inline float color_bone_vis[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
		static inline float color_bone_invis[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
		static inline float color_team_id[4] = { 1.0f, 1.0f, 0.0f, 1.0f };
		static inline float color_distance[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
		static inline float color_energy[4] = { 1.0f, 0.84f, 0.0f, 1.0f };
		static inline float color_kills[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
		static inline float color_name[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
		static inline float color_weapon[4] = { 1.0f, 0.5f, 0.0f, 1.0f };
		static inline float color_action[4] = { 1.0f, 0.0f, 1.0f, 1.0f };
		static inline float color_line[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
		static inline float color_warning[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
		static inline float color_aim_warning[4] = { 1.0f, 0.2f, 0.2f, 1.0f };
		static inline float color_info_warning[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
		static inline float color_fov[4] = { 1.0f, 1.0f, 1.0f, 1.0f }; // 自瞄FOV颜色
		static inline float color_trigger_fov[4] = { 0.0f, 1.0f, 0.0f, 1.0f }; // 扳机FOV颜色
		static inline float color_aim_line[4] = { 1.0f, 0.0f, 0.0f, 1.0f }; // 自瞄射线颜色
		static inline float color_target_bone[4] = { 1.0f, 1.0f, 0.0f, 1.0f }; // 瞄准点颜色

		// 线条粗细
		static inline float width_bone = 1.0f;
		static inline float width_box = 1.0f;
		static inline float width_line = 1.0f;

		// 文字大小
		static inline float size_team_id = 14.0f;
		static inline float size_kills = 14.0f;
		static inline float size_name = 14.0f;
		static inline float size_weapon = 14.0f;
		static inline float size_energy = 14.0f;
		static inline float size_distance = 14.0f;
		static inline float size_action = 14.0f;
		static inline float size_aim_warning = 18.0f;
		static inline float size_info_warning = 20.0f;

		// 信息预警位置
		static inline float info_warning_x = 0.5f; // 0.0 ~ 1.0 (屏幕比例)
		static inline float info_warning_y = 20.0f; // 绝对像素

		// 射线位置
		static inline int line_pos = 0; // 0: Top, 1: Center, 2: Bottom

		// 菜单按键
		static inline int menu_key = 0x24; // VK_HOME
		static inline bool show_menu = true;

		static inline bool item = true;
		static inline bool show_all_classes = false;
		static inline bool show_physx_models = false;
		static inline bool metro_mode = false;
		static inline bool metro_monster = true;
		static inline bool snow_effect = false; // 下雪动画开关

		// 雷达设置
		static inline bool radar = false;
		static inline int radar_style = 0; // 0: 军事, 1: 电竞
		static inline bool radar_name = false;
		static inline bool radar_vehicle = false;
		static inline bool radar_dis = false;
		static inline bool radar_ai = false;
		static inline bool radar_item = false;
		static inline float radar_x = 200.0f;
		static inline float radar_y = 200.0f;
		static inline float radar_size = 200.0f;
		static inline float radar_range = 100.0f; // 米


	};

	static inline struct aim {
		static inline int aim_fov = 300;
		static inline bool aim_line = true;

		static inline bool enable = false;
		static inline float fov = 100.0f;
		static inline float smooth = 0.30f;  // 自瞄平滑
		static inline float dist = 200.0f;
		static inline float x = 0.5f; // 0.0-1.0
		static inline float y = 0.5f; // 0.0-1.0
		static inline int key1 = 0;
		static inline int key2 = 0;
		static inline bool show_fov = true;
		static inline bool prediction = true; // 新增预判开关
		static inline bool no_recoil = false; // 无后座/压枪
		static inline bool ignore_groggy = true; // 倒地不瞄
		static inline bool ignore_ai = false; // 自瞄忽略人机
		static inline bool vis_check = false; // 可视判断
		static inline bool bone_scan = true; // 漏打自瞄 (legacy, mapped to aim_bone_mode)
		static inline int  aim_bone_mode = 0; // 0=仅头部, 1=漏打扫描, 2=固定部位, 3=随机部位
		static inline int  aim_bone_id = 6;   // 固定部位骨骼ID
		static inline bool humanize = false;   // 模拟真人
		static inline bool ignore_bow = false; // 弓箭不锁
		static inline bool ignore_empty = false; // 空仓不锁
		static inline bool auto_lock = true;  // 持续锁定（默认开启）
		static inline bool range_boost = false; // 50米增强
		static inline bool draw_line = true; // 自瞄射线
		static inline bool fire_aim = false; // 强制开火自瞄
		static inline bool dynamic_fov = false; // 动态范围
		static inline bool draw_target_bone = true; // 绘制瞄准骨骼点
		static inline bool silent_aim = false; // 静默自瞄开关
	};

	static inline struct trigger {
		static inline bool enable = false; // 自动扳机开关
		static inline bool aim_sync = false; // 扳机自瞄开关 (开启后扳机触发时也会触发自瞄)
		static inline bool show_fov = false; // 扳机范围绘制
		static inline float fov = 30.0f; // 扳机范围
		static inline int delay = 0; // 扳机延迟 (ms)
		static inline int key1 = 0; // 扳机按键1
		static inline int key2 = 0; // 扳机按键2
		static inline float aim_smooth = 5.0f; // 扳机自瞄速度
		static inline float aim_fov = 100.0f; // 扳机自瞄范围
		static inline bool show_aim_fov = false; // 扳机自瞄范围绘制
		static inline bool ignore_groggy = true; // 扳机忽略倒地
		static inline bool ignore_ai = false; // 扳机忽略人机
		static inline bool dynamic_fov = false; // 扳机动态范围
	};

	static inline struct shortcut {
		static inline bool enable = true; // 快捷键菜单显示
		static inline bool show_time = true; // 在线时间显示
		static inline bool show_status = true; // 游戏状态显示
		
		// 绑定按键
		static inline int key_toggle_menu = 0;   // 隐显菜单
		static inline int key_fusion = 0;        // 融合模式
		static inline int key_aim = 0;           // 自瞄启用
		static inline int key_meds = 0;          // 药品显示
		static inline int key_vehicle = 0;       // 载具显示
		static inline int key_weapon = 0;        // 显示枪械
		
		static inline bool fusion_mode = false;       // 融合模式状态
		
		// 外观设置
		static inline float x = 20.0f;
		static inline float y = 400.0f;
		static inline float color[4] = { 1.0f, 1.0f, 1.0f, 1.0f }; // 文字颜色
		static inline float size = 16.0f; // 字体大小
	};

};