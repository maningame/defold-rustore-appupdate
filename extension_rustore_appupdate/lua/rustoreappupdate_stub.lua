-- Stub for Defold Editor (autocomplete + diagnostics).
-- Runtime module is provided by native extension via luaL_register(MODULE_NAME, Module_methods).
-- Do not require this file.
--
-- Enums are available in global: RuStoreAppUpdateEnums (registered by native extension).

---@class rustoreappupdate
local M = {}

--- Инициализация AppUpdate (Android).
function M.init() end

--- Зарегистрировать listener обновлений.
-- @return boolean ok
function M.register_listener() end

--- Отписаться от listener обновлений.
-- @return boolean ok
function M.unregister_listener() end

--- Запросить AppUpdateInfo.
function M.get_appupdateinfo() end

--- Проверить, разрешено ли IMMEDIATE обновление.
-- @return boolean allowed
function M.check_is_immediate_update_allowed() end

--- Запустить IMMEDIATE update flow.
function M.start_update_flow_immediate() end

--- Запустить SILENT update flow.
function M.start_update_flow_silent() end

--- Запустить DELAYED update flow.
function M.start_update_flow_delayed() end

--- Завершить SILENT обновление.
function M.complete_update_silent() end

--- Завершить FLEXIBLE обновление.
function M.complete_update_flexible() end

---@type rustoreappupdate
rustoreappupdate = rustoreappupdate
